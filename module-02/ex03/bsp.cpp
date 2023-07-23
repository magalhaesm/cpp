/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 12:33:52 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/07/23 12:48:57 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed abs(const Fixed& x);
static Fixed calculateArea(const Point& a, const Point& b, const Point& c);

/**
 * @brief Checks if a point lies inside a triangle defined by three vertices.
 *
 * This function determines whether a given point is inside a triangle formed by
 * three vertices (a, b, c).
 *
 * To perform the check, the function uses the cross product method to determine
 * the orientation of the point with respect to each edge of the triangle. This is
 * done by calculating the area of three sub-triangles formed by the combinations of
 * points (a, b, point), (b, c, point), and (c, a, point). If the point is inside
 * the triangle, the sum of the areas of these sub-triangles will be equal to the
 * area of the original triangle. Otherwise, the point will be outside the triangle.
 *
 * @note If the point is collinear with any of the edges or vertices of the triangle,
 * it is considered outside the triangle.
 *
 * The function handles triangles with both counter-clockwise and clockwise orientation.
 *
 * @param a The first vertex of the triangle.
 * @param b The second vertex of the triangle.
 * @param c The third vertex of the triangle.
 * @param point The point to be checked.
 *
 * @return True if the point is inside the triangle, false otherwise.
 */
bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed areaABC = calculateArea(a, b, c);
    Fixed areaPAB = calculateArea(point, a, b);
    Fixed areaPBC = calculateArea(point, b, c);
    Fixed areaPCA = calculateArea(point, c, a);

    if (areaPAB == 0 || areaPBC == 0 || areaPCA == 0)
    {
        return false;
    }

    return (areaABC == areaPAB + areaPBC + areaPCA);
}

/**
 * @brief Calculates the area of a triangle formed by three points.
 *
 * @param a The first vertex of the triangle.
 * @param b The second vertex of the triangle.
 * @param c The third vertex of the triangle.
 * @return The area of the triangle.
 */
static Fixed calculateArea(const Point& a, const Point& b, const Point& c)
{
    Fixed term1 = a.getX() * (b.getY() - c.getY());
    Fixed term2 = b.getX() * (c.getY() - a.getY());
    Fixed term3 = c.getX() * (a.getY() - b.getY());

    Fixed area = (term1 + term2 + term3) / 2.0f;

    return abs(area);
}

/**
 * @brief Calculates the absolute value of a number.
 *
 * @param number The number whose absolute value will be calculated.
 * @return The absolute value of the given number.
 */
static Fixed abs(const Fixed& number)
{
    return (number < 0) ? number * -1 : number;
}
