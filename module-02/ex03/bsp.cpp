/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 12:33:52 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/07/22 18:55:28 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed verticalDistance(const Point& a, const Point& b);
static Fixed horizontalDistance(const Point& a, const Point& b);
static Fixed calcCrossProduct(const Point& a, const Point& b, const Point& c);

/**
 * @brief Check if a point lies inside a triangle defined by three vertices.
 *
 * This function determines whether a given point is inside a triangle formed by
 * three vertices (a, b, c).
 * It uses the cross product to check the orientation of the point with respect
 * to each edge of the triangle.
 * The function returns true if the point is inside the triangle, and false otherwise.
 * @note If the point is collinear with any of the edges or vertices of the triangle,
 * it is considered outside.
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
    Fixed cp1 = calcCrossProduct(b, a, point);
    Fixed cp2 = calcCrossProduct(c, b, point);
    Fixed cp3 = calcCrossProduct(a, c, point);

    return (cp1 < 0 && cp2 < 0 && cp3 < 0) || (cp1 > 0 && cp2 > 0 && cp3 > 0);
}

/**
 * @brief Calculate the horizontal distance between two 2D points (a and b).
 *
 * This function calculates the horizontal distance between two 2D points
 * (a and b) along the x-axis.
 *
 * @param a The first 2D point.
 * @param b The second 2D point.
 *
 * @return The horizontal distance between points a and b.
 */
static Fixed horizontalDistance(const Point& a, const Point& b)
{
    return a.getX() - b.getX();
}

/**
 * @brief Calculate the vertical distance between two 2D points (a and b).
 *
 * This function calculates the vertical distance between two 2D points (a and b)
 * along the y-axis.
 *
 * @param a The first 2D point.
 * @param b The second 2D point.
 *
 * @return The vertical distance between points a and b.
 */
static Fixed verticalDistance(const Point& a, const Point& b)
{
    return a.getY() - b.getY();
}

/**
 * @brief Calculate the cross product of three 2D points (vectors).
 *
 * This function calculates the cross product of three 2D points (a, b, c)
 * represented as vectors.
 * The cross product is a measure of the signed area of the parallelogram
 * formed by the vectors a and b with respect to the vector c.
 *
 * @param a The first 2D point (vector) a.
 * @param b The second 2D point (vector) b.
 * @param c The third 2D point (vector) c.
 *
 * @return The cross product of the vectors a, b, and c. It returns 0 if the
 *         points are collinear.
 */
static Fixed calcCrossProduct(const Point& a, const Point& b, const Point& c)
{
    Fixed hvProduct = horizontalDistance(a, b) * verticalDistance(c, b);
    Fixed vhProduct = verticalDistance(a, b) * horizontalDistance(c, b);

    return hvProduct - vhProduct;
}
