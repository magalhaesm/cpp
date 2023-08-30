/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 13:23:42 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/08/26 09:48:13 by mdias-ma         ###   ########.fr       */
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
     * @brief Advances the iterator `it` by `n` positions.
     *
     * @param it The iterator to advance.
     * @param n  The number of positions to advance the iterator.
     */
    template <typename Iterator, typename Distance>
    void advance(Iterator& it, Distance n = 1);

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
            while (n > 0)
            {
                --it;
                --n;
            }
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
            while (n--)
            {
                ++it;
            }
            return it;
        }

        template <typename RandomAccessIterator, typename Distance>
        inline void advance(RandomAccessIterator& it, Distance n, std::random_access_iterator_tag)
        {
            it += n;
        }

        template <typename BidirectionalIterator, typename Distance>
        inline void advance(BidirectionalIterator& it, Distance n, std::bidirectional_iterator_tag)
        {
            if (n >= 0)
            {
                while (n > 0)
                {
                    ++it;
                    --n;
                }
            }
            else
            {
                while (n < 0)
                {
                    --it;
                    ++n;
                }
            }
        }
    }
}

template <typename Iterator, typename Distance>
void utils::advance(Iterator& it, Distance n)
{
    typename std::iterator_traits<Iterator>::iterator_category category;
    impl::advance(it, n, category);
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
