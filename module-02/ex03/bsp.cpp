/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 12:33:52 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/07/20 15:23:30 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed verticalDistance(const Point& p1, const Point& p2);
static Fixed horizontalDistance(const Point& p1, const Point& p2);
static Fixed calcCrossProduct(const Point& p1, const Point& p2, const Point& p3);
static bool areCollinear(const Point& p1, const Point& p2, const Point& p3);

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    if (areCollinear(a, b, point) || areCollinear(b, c, point) || areCollinear(c, a, point))
    {
        return false;
    }

    Fixed r1 = calcCrossProduct(b, a, point);
    Fixed r2 = calcCrossProduct(c, b, point);
    Fixed r3 = calcCrossProduct(a, c, point);

    return (r1 >= 0 && r2 >= 0 && r3 >= 0) || (r1 <= 0 && r2 <= 0 && r3 <= 0);
}

static bool areCollinear(const Point& p1, const Point& p2, const Point& p3)
{
    Fixed cross_product;

    cross_product = p1.getX() * (p2.getY() - p3.getY());
    cross_product += p2.getX() * (p3.getY() - p1.getY());
    cross_product += p3.getX() * (p1.getY() - p2.getY());

    return cross_product == 0;
}

static Fixed horizontalDistance(const Point& p1, const Point& p2)
{
    return p1.getX() - p2.getX();
}

static Fixed verticalDistance(const Point& p1, const Point& p2)
{
    return p1.getY() - p2.getY();
}

static Fixed calcCrossProduct(const Point& p1, const Point& p2, const Point& p3)
{
    Fixed hvProduct = horizontalDistance(p1, p2) * verticalDistance(p3, p2);
    Fixed vhProduct = verticalDistance(p1, p2) * horizontalDistance(p3, p2);

    return hvProduct - vhProduct;
}
