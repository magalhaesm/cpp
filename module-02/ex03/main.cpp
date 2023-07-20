/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 15:54:30 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/07/20 15:33:22 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cassert>
#include <string>

#include "Point.hpp"

#define PASSED "\033[1;7;32m PASSED \033[0m "

bool bsp(Point const a, Point const b, Point const c, Point const point);
void printTestPassed(const std::string& testName);

int main(void)
{
    Point p1(0, 0);
    Point p2(4, 0);
    Point p3(0, 3);

    Point insidePoint(1, 1);
    assert(bsp(p1, p2, p3, insidePoint) == true);
    printTestPassed("Inside point");

    Point outsidePoint(5, 2);
    assert(bsp(p1, p2, p3, outsidePoint) == false);
    printTestPassed("Outside point");

    Point edgePoint(2, 0);
    assert(bsp(p1, p2, p3, edgePoint) == false);
    printTestPassed("Edge point");

    return EXIT_SUCCESS;
}

void printTestPassed(const std::string& testName)
{
    std::cout << PASSED << testName << " test." << std::endl;
}
