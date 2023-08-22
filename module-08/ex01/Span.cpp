/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 17:25:04 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/08/12 00:29:11 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span()
    : m_updated(false)
    , m_size(0)
    , m_numbers()
    , m_diff()
{
}

Span::Span(unsigned int size)
    : m_updated(false)
    , m_size(size)
    , m_numbers()
    , m_diff()
{
}

Span::Span(const Span& copy)
    : m_updated(false)
    , m_size(copy.m_size)
    , m_numbers(copy.m_numbers)
    , m_diff(copy.m_diff)
{
}

Span::~Span()
{
}

Span& Span::operator=(const Span& rhs)
{
    if (&rhs != this)
    {
        m_updated = rhs.m_updated;
        m_size = rhs.m_size;
        m_numbers = rhs.m_numbers;
        m_diff = rhs.m_diff;
    }
    return *this;
}

void Span::addNumber(int n)
{
    if (m_numbers.size() + 1 > m_size)
    {
        throw std::runtime_error("Cannot add number: span size limit exceeded");
    }
    m_numbers.push_back(n);
    m_updated = false;
}

void Span::addNumber(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end)
{
    size_t rangeSize = static_cast<size_t>(std::distance(begin, end));
    if (m_numbers.size() + rangeSize > m_size)
    {
        throw std::runtime_error("Cannot add range: span size limit exceeded");
    }

    m_numbers.insert(m_numbers.end(), begin, end);
    m_updated = false;
}

int Span::shortestSpan()
{
    update();
    std::vector<int>::const_iterator it = std::min_element(m_diff.begin(), m_diff.end());
    return *it;
}

int Span::longestSpan()
{
    update();
    std::vector<int>::const_iterator it = std::max_element(m_diff.begin(), m_diff.end());
    return *it;
}

void Span::update()
{
    if (m_updated)
    {
        return;
    }
    if (m_numbers.size() <= 1)
    {
        throw std::runtime_error("Cannot calculate span: insufficient number of elements.");
    }
    m_diff.resize(m_numbers.size());
    std::adjacent_difference(m_numbers.begin(), m_numbers.end(), m_diff.begin());
    std::transform(m_diff.begin(), m_diff.end(), m_diff.begin(), abs);
    m_updated = true;
}
