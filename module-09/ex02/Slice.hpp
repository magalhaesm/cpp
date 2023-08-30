/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Slice.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 09:47:40 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/08/30 17:52:10 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SLICE_HPP
#define SLICE_HPP

#include <iostream>
#include <algorithm>

template <typename Iterator>
class Slice
{
private:
    Iterator m_begin;
    size_t m_size;

public:
    typedef Iterator iterator_type;
    typedef typename std::iterator_traits<Iterator>::value_type value_type;
    typedef typename std::iterator_traits<Iterator>::reference reference;

    Slice(Iterator begin, size_t size)
        : m_begin(begin)
        , m_size(size)
    {
    }

    Iterator base() const
    {
        return m_begin;
    }

    std::size_t size() const
    {
        return m_size;
    }

    reference operator*() const
    {
        return m_begin[m_size - 1];
    }

    // NOTE: OK
    bool operator<(const Slice<Iterator>& rhs) const
    {
        return *(this->base() + m_size - 1) < *(rhs.base() + rhs.m_size - 1);
    }

    Slice<Iterator> operator+(size_t count) const
    {
        return Slice<Iterator>(m_begin + (m_size * count), m_size);
    }

    // NOTE: OK
    reference operator[](size_t pos) const
    {
        return m_begin[pos * m_size + m_size - 1];
    }

    Slice& operator+=(size_t increment)
    {
        m_begin += m_size * increment;
        return *this;
    }
};

template <typename Iterator>
void iter_swap(Slice<Iterator> rhs, Slice<Iterator> lhs)
{
    Iterator middle = rhs.base() + rhs.size();
    std::swap_ranges(rhs.base(), middle, lhs.base());
}

template <typename Iterator>
std::ostream& operator<<(std::ostream& os, const Slice<Iterator>& slice)
{
    os << "[";
    for (size_t idx = 0; idx < slice.size(); ++idx)
    {
        os << *(slice.base() + idx);
        if (idx < slice.size() - 1)
        {
            os << ", ";
        }
    }
    os << "]";
    return os;
}

#endif // !SLICE_HPP
