/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 20:43:28 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/08/17 21:11:36 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <sstream>
#include <iostream>
#include <stdexcept>

#include "RPN.hpp"

void checkInvalidNumber(const std::string& str);
int safetyDivision(int term1, int term2);

std::list<int> RPN::m_stack;

RPN::RPN()
{
}

int RPN::eval(const std::string& expression)
{
    checkInvalidNumber(expression);
    std::istringstream input(expression);

    char ch;
    while (input >> ch)
    {
        switch (lookup(ch))
        {
        case NUMBER:
            processNumber(ch);
            break;
        case OPERATOR:
            processOperator(ch);
            break;
        }
    }
    return m_stack.back();
}

void RPN::processNumber(char digit)
{
    m_stack.push_back(digit - '0');
}

TokenType RPN::lookup(char ch)
{
    if (std::isdigit(ch))
    {
        return NUMBER;
    }
    return OPERATOR;
}

void RPN::assign(int& term1, int& term2)
{
    if (m_stack.size() < 2)
    {
        throw std::runtime_error("invalid operation");
    }

    term2 = m_stack.back();
    m_stack.pop_back();

    term1 = m_stack.back();
    m_stack.pop_back();
}

void RPN::processOperator(char op)
{
    int term1, term2;
    assign(term1, term2);

    int result = 0;
    switch (op)
    {
    case '+':
        result = term1 + term2;
        break;
    case '-':
        result = term1 - term2;
        break;
    case '*':
        result = term1 * term2;
        break;
    case '/':
        result = safetyDivision(term1, term2);
        break;
    default:
        throw std::runtime_error("invalid operator");
    }

    m_stack.push_back(result);
}

int safetyDivision(int term1, int term2)
{
    if (term2 != 0)
    {
        return term1 / term2;
    }
    else
    {
        throw std::runtime_error("division by zero");
    }
}

void checkInvalidNumber(const std::string& str)
{
    for (size_t i = 0; i < str.length() - 1; ++i)
    {
        if ((std::isdigit(str[i])) && std::isdigit(str[i + 1]))
        {
            throw std::runtime_error("only single-digit numbers are allowed");
        }
    }
}
