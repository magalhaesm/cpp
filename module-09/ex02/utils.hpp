/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 13:23:42 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/09/04 16:02:52 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP

#include <iterator>

namespace utils
{
    /**
     * @brief Moves the iterator `it` backwards by `n` positions.
     *
     * @param it The iterator to move.
     * @param n  The number of positions to move the iterator backwards.
     * @return Iterator pointing to the new position.
     */
    template <typename Iterator>
    Iterator prev(Iterator it, size_t n = 1);

    /**
     * @brief Moves the iterator `it` forwards by `n` positions.
     *
     * @param it The iterator to move.
     * @param n  The number of positions to move the iterator forwards.
     * @return Iterator pointing to the new position.
     */
    template <typename Iterator>
    Iterator next(Iterator it, size_t n = 1);

    /**
     * Check if a range of elements is sorted in ascending order.
     *
     * This function checks whether the range defined by the iterators 'first' and 'last'
     * is sorted in ascending order based on element comparisons.
     *
     * @param first The iterator to the first element in the range.
     * @param last The iterator to the last element in the range.
     * @return True if the range is sorted in ascending order, otherwise False.
     */
    template <typename ForwardIterator>
    bool is_sorted(ForwardIterator first, ForwardIterator last)
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

    namespace impl
    {
        template <typename RandomAccessIterator>
        inline RandomAccessIterator
        prev(RandomAccessIterator it, size_t n, std::random_access_iterator_tag)
        {
            return it - n;
        }

        template <typename BidirectionalIterator>
        inline BidirectionalIterator
        prev(BidirectionalIterator it, size_t n, std::bidirectional_iterator_tag)
        {
            std::advance(it, -n);
            return it;
        }

        template <typename RandomAccessIterator>
        inline RandomAccessIterator
        next(RandomAccessIterator it, size_t n, std::random_access_iterator_tag)
        {
            return it + n;
        }

        template <typename BidirectionalIterator>
        inline BidirectionalIterator
        next(BidirectionalIterator it, size_t n, std::bidirectional_iterator_tag)
        {
            std::advance(it, n);
            return it;
        }

    }
}

template <typename Iterator>
Iterator utils::prev(Iterator it, size_t n)
{
    typename std::iterator_traits<Iterator>::iterator_category category;
    return impl::prev(it, n, category);
}

template <typename Iterator>
Iterator utils::next(Iterator it, size_t n)
{
    typename std::iterator_traits<Iterator>::iterator_category category;
    return impl::next(it, n, category);
}

#endif // !UTILS_HPP
