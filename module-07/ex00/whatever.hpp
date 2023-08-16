/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:26:09 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/08/16 20:15:57 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
void swap(T& x, T& y)
{
    T temp;

    temp = x;
    x = y;
    y = temp;
}

template <typename T>
const T& min(const T& x, const T& y)
{
    return (x < y) ? x : y;
}

template <typename T>
const T& max(const T& x, const T& y)
{
    return (x > y) ? x : y;
}

#endif // !WHATEVER_HPP
