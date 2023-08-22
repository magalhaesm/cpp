/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 12:41:01 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/08/22 14:13:16 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <algorithm>

namespace PmergeMe
{
    template <typename Iterator>
    void sort(Iterator first, Iterator last);

    template <typename Iterator>
    void mergeInsertionSort(Iterator first, Iterator last, size_t size = 2);

    template <typename Iterator>
    void maxEndSwap(const Iterator it, size_t group_size);

    template <typename ForwardIterator>
    bool isSorted(ForwardIterator first, ForwardIterator last);
};

template <typename Iterator>
void PmergeMe::sort(Iterator first, Iterator last)
{
    mergeInsertionSort(first, last, 2);
}

template <typename Iterator>
inline void PmergeMe::mergeInsertionSort(Iterator first, Iterator last, size_t size)
{
    size_t elements = std::distance(first, last);
    if (size > elements) // base case
    {
        return;
    }

    Iterator ite = last - (elements % size);
    for (Iterator it = first; it < ite; it += size)
    {
        maxEndSwap(it, size);
    }
    mergeInsertionSort(first, last, size * 2);
}

template <typename Iterator>
inline void PmergeMe::maxEndSwap(const Iterator it, size_t size)
{
    Iterator left_end = it + (size / 2);
    Iterator right_end = it + size;

    int left = *(left_end - 1);
    int right = *(right_end - 1);

    if (left > right)
    {
        std::swap_ranges(it, left_end, left_end);
    }
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
