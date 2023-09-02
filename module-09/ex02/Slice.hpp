
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Slice.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 09:47:40 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/09/02 15:19:37 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SLICE_HPP
#define SLICE_HPP

#include <iostream>
#include <algorithm>

#include "utils.hpp"

template <typename Iterator>
class Slice
{
public:
    typedef typename std::iterator_traits<Iterator>::value_type value_type;
    typedef typename std::iterator_traits<Iterator>::difference_type difference_type;
    typedef typename std::iterator_traits<Iterator>::pointer pointer;
    typedef typename std::iterator_traits<Iterator>::reference reference;
    typedef typename std::iterator_traits<Iterator>::iterator_category iterator_category;

private:
    Iterator m_begin;
    size_t m_size;

public:
    Slice()
    {
    }

    ~Slice()
    {
    }

    Slice(Iterator it, size_t size)
        : m_begin(it)
        , m_size(size)
    {
    }

    Iterator base() const
    {
        return m_begin;
    }

    size_t size() const
    {
        return m_size;
    }

    reference operator*() const
    {
        return *utils::next(m_begin, m_size - 1);
    }

    Slice& operator+=(size_t increment)
    {
        m_begin += increment * m_size;
        return *this;
    }

    Slice& operator-=(size_t increment)
    {
        m_begin -= increment * m_size;
        return *this;
    }

    bool operator!=(const Slice& rhs) const
    {
        return this->base() != rhs.base();
    }

    Slice operator+(size_t size) const
    {
        Slice aux = *this;
        return aux += size;
    }

    Slice operator-(size_t size) const
    {
        Slice aux = *this;
        return aux -= size;
    }

    size_t operator-(const Slice& rhs) const
    {
        return std::distance(this->base(), rhs.base()) / this->size();
    }
};

template <typename Slice>
bool operator<(const Slice& lhs, const Slice& rhs)
{
    return *lhs < *rhs;
}

template <typename Iterator>
Slice<Iterator> make_slice(Iterator it, size_t size)
{
    return Slice<Iterator>(it, size);
}

template <typename Iterator>
Slice<Iterator> make_slice(Slice<Iterator> it, size_t size)
{
    size *= it.size();
    return Slice<Iterator>(it.base(), size);
}

template <typename Slice>
void iter_swap(Slice lhs, Slice rhs)
{
    std::swap_ranges(lhs.base(), utils::next(lhs.base(), lhs.size()), rhs.base());
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
