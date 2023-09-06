/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 17:16:09 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/09/06 14:05:31 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>
#include <iostream>

template <typename T>
void iter(T* array, size_t length, void (*function)(T&))
{
    if (!array)
    {
        return;
    }

    for (size_t idx = 0; idx < length; ++idx)
    {
        function(array[idx]);
    }
}

template <typename T>
void iter(const T* array, const size_t length, void (*function)(const T&))
{
    if (!array)
    {
        return;
    }

    for (size_t idx = 0; idx < length; ++idx)
    {
        function(array[idx]);
    }
}

template <typename T>
void printElement(T element)
{
    std::cout << element << ' ';
}

template <typename T>
void doubleElement(T element)
{
    std::cout << element + element << ' ';
}

#endif // !ITER_HPP
