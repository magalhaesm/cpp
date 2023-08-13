/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 12:14:29 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/08/13 18:00:43 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

Point::Point()
    : x(0)
    , y(0)
{
}

Point::Point(const float x, const float y)
    : x(x)
    , y(y)
{
}

Point::Point(const Point& src)
    : x(src.getX())
    , y(src.getY())
{
}

Point& Point::operator=(const Point&)
{
    return *this;
}

Point::~Point()
{
}

Fixed Point::getX() const
{
    return x;
}

Fixed Point::getY() const
{
    return y;
}
