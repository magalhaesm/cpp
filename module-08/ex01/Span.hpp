/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 17:24:09 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/08/11 21:55:38 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <numeric>
#include <algorithm>
#include <stdexcept>

class Span
{
public:
    Span(unsigned int size);
    Span(const Span& copy);
    ~Span();
    Span& operator=(const Span& rhs);

    void addNumber(int n);
    void addNumber(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end);

    int shortestSpan();
    int longestSpan();

private:
    Span();

    bool m_updated;
    size_t m_size;
    std::vector<int> m_numbers;
    std::vector<int> m_diff;

    void update();
};

#endif // !SPAN_HPP
