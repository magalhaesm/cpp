/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 13:22:11 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/08/02 18:37:35 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <string>
#include <iostream>

#include "ScalarConverter.hpp"
#include "ConversionStrategy.hpp"

void ScalarConverter::convert(const std::string& literal)
{
    ScalarType type = parseScalarType(literal);
    AConversionStrategy* strategy = 0;

    switch (type)
    {
    case CHAR:
        strategy = new CharConversionStrategy();
        break;
    case INT:
        strategy = new IntConversionStrategy();
        break;
    case FLOAT:
        strategy = new FloatConversionStrategy();
        break;
    case DOUBLE:
        strategy = new DoubleConversionStrategy();
        break;
    case PSEUDO:
        strategy = new PseudoLiteralConversionStrategy();
        break;
    case UNKNOWN:
        strategy = new InvalidConversionStrategy();
    }

    strategy->convert(literal);
    delete strategy;
}

ScalarType ScalarConverter::parseScalarType(const std::string& literal)
{
    if (!literal.length())
    {
        return UNKNOWN;
    }

    ScalarType type = UNKNOWN;

    type = parseChar(literal);
    if (type != UNKNOWN)
    {
        return type;
    }

    type = parseNumber(literal);
    if (type != UNKNOWN)
    {
        return type;
    }

    type = parsePseudoLiteral(literal);
    if (type != UNKNOWN)
    {
        return type;
    }

    return UNKNOWN;
}

ScalarType ScalarConverter::parseChar(const std::string& literal)
{
    if (literal.length() == 1 && !std::isdigit(literal[0]))
    {
        return CHAR;
    }
    return UNKNOWN;
}

static bool isSign(char c)
{
    return c == '+' || c == '-';
}

ScalarType ScalarConverter::parseNumber(const std::string& literal)
{
    bool hasDot = false;
    bool hasF = false;

    size_t idx = 0;

    if (isSign(literal[idx]))
    {
        ++idx;
    }

    size_t length = literal.length();
    while (idx < length)
    {
        char currentChar = literal[idx];

        if (currentChar == '.')
        {
            if (hasDot)
                return UNKNOWN;
            hasDot = true;
        }
        else if (currentChar == 'f' || currentChar == 'F')
        {
            if (hasF)
                return UNKNOWN;
            hasF = true;
        }
        else if (!std::isdigit(currentChar))
        {
            return UNKNOWN;
        }
        idx++;
    }

    if (hasF)
    {
        return FLOAT;
    }
    return hasDot ? DOUBLE : INT;
}

ScalarType ScalarConverter::parsePseudoLiteral(const std::string& literal)
{
    if (literal == "nan" || literal == "nanf")
    {
        return PSEUDO;
    }
    if (literal == "inff" || literal == "-inff" || literal == "+inff")
    {
        return PSEUDO;
    }
    else if (literal == "inf" || literal == "-inf" || literal == "+inf")
    {
        return PSEUDO;
    }

    return UNKNOWN;
}
