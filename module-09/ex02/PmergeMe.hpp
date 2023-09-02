/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 12:41:01 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/09/02 16:56:20 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <list>
#include <vector>
#include <algorithm>

#include "utils.hpp"

namespace PmergeMe
{
    template <typename Iterator>
    void sort(Iterator first, Iterator last);

    template <typename Slice>
    void sort_impl(Slice first, Slice last);

    template <typename ForwardIterator>
    bool isSorted(ForwardIterator first, ForwardIterator last);
};

template <typename Iterator>
void PmergeMe::sort(Iterator first, Iterator last)
{
    sort_impl(make_slice(first, 1), make_slice(last, 1));
}

template <typename T>
struct Inserter
{
    std::vector<T>& m_chain;

    Inserter(std::vector<T>& chain)
        : m_chain(chain)
    {
    }

    void operator()(const T& element, size_t max_insertion_idx)
    {
        typedef typename std::vector<T>::iterator Iterator;

        Iterator end = m_chain.begin() + std::min(max_insertion_idx, m_chain.size());
        Iterator idx = std::upper_bound(m_chain.begin(), end, element);
        m_chain.insert(idx, element);
    }
};

template <typename Container, typename Function>
void each_insertion_for(const Container& pend, Function inserter)
{
    inserter(pend[0], 0);

    size_t groupIdx = 1;
    size_t prevGroupSize = 0;

    for (size_t power = 1; groupIdx < pend.size(); ++power)
    {
        size_t groupSize = (1 << power) - prevGroupSize;
        size_t groupLast = std::min(groupIdx + groupSize - 1, pend.size() - 1);
        size_t maxInsertionIdx = (1 << (power + 1)) - 1;

        for (size_t idx = groupLast; idx >= groupIdx; --idx)
        {
            inserter(pend[idx], maxInsertionIdx);
        }

        groupIdx += groupSize;
        prevGroupSize = groupSize;
    }
}

template <typename Slice>
void PmergeMe::sort_impl(Slice first, Slice last)
{
    size_t size = std::distance(first, last);
    if (size < 2)
    {
        return;
    }

    bool odd = (size % 2 != 0);
    Slice end = odd ? utils::prev(last) : last;

    for (Slice it = first; it != end; it += 2)
    {
        if (*(it + 1) < *it)
        {
            iter_swap(it + 1, it);
        }
    }

    sort_impl(make_slice(first, 2), make_slice(end, 2));

    std::vector<Slice> chain;
    std::vector<Slice> pend;

    for (Slice it = first; it != end; it += 2)
    {
        pend.push_back(it);
        chain.push_back(it + 1);
    }

    if (odd)
    {
        pend.push_back(utils::prev(last));
    }

    Inserter<Slice> inserter(chain);
    each_insertion_for(pend, inserter);

    std::vector<typename Slice::value_type> sorted;

    for (size_t i = 0; i < chain.size(); ++i)
    {
        Slice slice = chain[i];
        for (size_t j = 0; j < slice.size(); ++j)
        {
            sorted.push_back(*(slice.base() + j));
        }
    }
    std::copy(sorted.begin(), sorted.end(), first.base());
}

template <typename ForwardIterator>
bool PmergeMe::isSorted(ForwardIterator first, ForwardIterator last)
{
    if (first == last)
    {
        return true;
    }

    ForwardIterator next = first;
    while (++next != last)
    {
        if (*next < *first)
        {
            return false;
        }
        ++first;
    }
    return true;
}

#endif // !PMERGEME_HPP
