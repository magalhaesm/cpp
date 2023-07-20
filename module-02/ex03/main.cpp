/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 15:54:30 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/07/20 20:32:39 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cassert>
#include <string>

#include "Point.hpp"

#define PASSED "\033[1;7;32m PASSED \033[0m "

bool bsp(Point const a, Point const b, Point const c, Point const point);
void printTestPassed(const std::string& testName);

void testClockwiseTriangle(void);
void testCounterClockwiseTriangle(void);

int main(void)
{
    testClockwiseTriangle();
    testCounterClockwiseTriangle();

    return EXIT_SUCCESS;
}

void testClockwiseTriangle(void)
{
    Point a(2, 3);
    Point b(4, 0);
    Point c(0, 0);

    Point insidePoint(1, 1);
    assert(bsp(a, b, c, insidePoint) == true);
    printTestPassed("Inside point (Clockwise triangle)");

    Point outsidePoint(5, 2);
    assert(bsp(a, b, c, outsidePoint) == false);
    printTestPassed("Outside point (Clockwise triangle)");

    Point edgePoint(2, 0);
    assert(bsp(a, b, c, edgePoint) == false);
    printTestPassed("Edge point (Clockwise triangle)");

    assert(bsp(a, b, c, a) == false);
    printTestPassed("Vertex (Clockwise triangle)");
}

void testCounterClockwiseTriangle(void)
{
    Point a(0, 0);
    Point b(4, 0);
    Point c(2, 3);

    Point insidePoint(1, 1);
    assert(bsp(a, b, c, insidePoint) == true);
    printTestPassed("Inside point (Counter-clockwise triangle)");

    Point outsidePoint(5, 2);
    assert(bsp(a, b, c, outsidePoint) == false);
    printTestPassed("Outside point (Counter-clockwise triangle)");

    Point edgePoint(2, 0);
    assert(bsp(a, b, c, edgePoint) == false);
    printTestPassed("Edge point (Counter-clockwise triangle)");

    assert(bsp(a, b, c, a) == false);
    printTestPassed("Vertex (Counter-clockwise triangle)");
}

void printTestPassed(const std::string& testName)
{
    std::cout << PASSED << testName << std::endl;
}
