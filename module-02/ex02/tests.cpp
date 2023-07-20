/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 18:51:30 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/07/20 11:48:07 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cassert>
#include <string>

#include "Fixed.hpp"

#define PASSED "\033[1;7;32m PASSED \033[0m "

void testAssignment(void);
void testComparison(void);
void testArithmetic(void);
void testArithmetic(void);
void testIncrementDecrement(void);
void testMin(void);
void testMax(void);
void printTestPassed(const std::string& testName);

int main(void)
{
    testAssignment();
    testComparison();
    testArithmetic();
    testIncrementDecrement();
    testMin();
    testMax();
    return 0;
}

void printTestPassed(const std::string& testName)
{
    std::cout << PASSED << testName << " test." << std::endl;
}

void testAssignment(void)
{
    Fixed a(5);
    Fixed b = a;

    assert(a == b);
    printTestPassed("Assignment operator");
}

void testComparison(void)
{
    Fixed a(5);
    Fixed b(10);

    assert(a < b);
    assert(b > a);
    assert(a <= b);
    assert(b >= a);
    assert(a != b);
    a = b;
    assert(a == b);
    printTestPassed("Comparison operators");
}

void testArithmetic(void)
{
    Fixed a(5);
    Fixed b(10);
    Fixed c = a + b;

    assert(c == 15);
    c = a - b;
    assert(c == -5);
    c = a * b;
    assert(c == 50);
    c = b / a;
    assert(c == 2);
    printTestPassed("Arithmetic operators");
}

void testIncrementDecrement(void)
{
    Fixed a(5);

    a++;
    assert(a == 5.00391f);
    a--;
    assert(a == 5);
    ++a;
    assert(a == 5.00391f);
    --a;
    assert(a == 5);
    printTestPassed("Increment and decrement operators");
}

void testMin(void)
{
    Fixed a(5);
    Fixed b(10);

    assert(Fixed::min(a, b) == a);
    printTestPassed("Min function");
}

void testMax(void)
{
    Fixed a(5);
    Fixed b(10);

    assert(Fixed::max(a, b) == b);
    printTestPassed("Max function");
}
