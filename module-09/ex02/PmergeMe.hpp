/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 12:41:01 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/09/04 15:41:10 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <list>
#include <vector>
#include <algorithm>

#include "Slice.hpp"
#include "utils.hpp"

namespace PmergeMe
{
    template <typename Iterator>
    void sort(Iterator first, Iterator last);

    template <typename Slice, typename Compare>
    void sort_impl(Slice first, Slice last, Compare cmp);

    template <typename Container, typename Function>
    void each_insertion_for(const Container& pend, Function inserter);

    template <typename Slice>
    void collect_sorted(Slice& first, std::list<Slice>& chain);

    namespace impl
    {
        template <typename T, typename Compare>
        struct Inserter;
    }
};

template <typename Iterator>
void PmergeMe::sort(Iterator first, Iterator last)
{
    typedef Slice<Iterator> Slice;
    sort_impl(Slice(first), Slice(last), std::less<Slice>());
}

template <typename Slice, typename Compare>
void PmergeMe::sort_impl(Slice first, Slice last, Compare cmp)
{
    size_t size = std::distance(first, last);
    if (size < 2)
    {
        return;
    }

    bool odd = (size % 2 != 0);
    Slice end = odd ? utils::prev(last) : last;

    swap_adjacent(first, end, cmp);
    sort_impl(Slice(first, 2), Slice(end, 2), cmp);

    std::list<Slice> chain;
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

    impl::Inserter<Slice, Compare> inserter(chain, cmp);
    each_insertion_for(pend, inserter);

    collect_sorted(first, chain);
}

template <typename Container, typename Function>
void PmergeMe::each_insertion_for(const Container& pend, Function inserter)
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
void PmergeMe::collect_sorted(Slice& first, std::list<Slice>& chain)
{
    typedef typename std::list<Slice>::iterator Iterator;

    std::vector<typename Slice::value_type> sorted;

    for (Iterator it = chain.begin(); it != chain.end(); ++it)
    {
        Slice slice = *it;
        for (size_t idx = 0; idx < slice.size(); ++idx)
        {
            sorted.push_back(*(utils::next(slice.base(), idx)));
        }
    }
    std::copy(sorted.begin(), sorted.end(), first.base());
}

template <typename T, typename Compare>
struct PmergeMe::impl::Inserter
{
    std::list<T>& m_chain;
    Compare m_cmp;

    Inserter(std::list<T>& chain, Compare cmp)
        : m_chain(chain)
        , m_cmp(cmp)
    {
    }

    void operator()(const T& element, size_t maxInsertionIdx)
    {
        typedef typename std::list<T>::iterator Iterator;

        size_t maxIdx = std::min(maxInsertionIdx, m_chain.size());
        Iterator end = utils::next(m_chain.begin(), maxIdx);

        Iterator idx = std::upper_bound(m_chain.begin(), end, element, m_cmp);

        m_chain.insert(idx, element);
    }
};

#endif // !PMERGEME_HPP
