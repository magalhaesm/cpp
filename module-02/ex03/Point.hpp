/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 12:14:27 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/07/20 13:07:07 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
public:
    Point(void);
    Point(const float x, const float y);
    Point(const Point& src);
    Point& operator=(const Point& rhs);
    ~Point(void);

    Fixed getX(void) const;
    Fixed getY(void) const;

private:
    const Fixed x;
    const Fixed y;
};

#endif // !POINT_HPP
