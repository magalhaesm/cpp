/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 13:22:11 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/08/03 01:00:15 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <climits>
#include <cstdlib>
#include <limits>
#include <iostream>

#include "Parser.hpp"
#include "ScalarConverter.hpp"

static bool isInRange(long, long, long);
static double extractPseudoLiteral(const std::string&);

const ScalarConverter::ConversionEntry ScalarConverter::conversionTable[functions] = {
    { CHAR, ScalarConverter::charConversion },
    { INT, ScalarConverter::intConversion },
    { FLOAT, ScalarConverter::floatConversion },
    { DOUBLE, ScalarConverter::doubleConversion },
    { PSEUDO, ScalarConverter::pseudoLiteralConversion },
    { UNKNOWN, ScalarConverter::invalidConversion },
};

void ScalarConverter::convert(const std::string& literal)
{
    ScalarType type = Parser::parseScalarType(literal);

    for (int idx = 0; idx < functions; ++idx)
    {
        if (type == conversionTable[idx].type)
        {
            conversionTable[idx].convert(literal);
            break;
        }
    }
}

void ScalarConverter::charConversion(const std::string& literal)
{
    ConversionPack pack = newPack();
    char value = literal[0];

    pack.char_value = value;
    pack.int_value = static_cast<int>(value);
    pack.float_value = static_cast<float>(value);
    pack.double_value = static_cast<double>(value);

    std::cout << pack << std::endl;
}

void ScalarConverter::intConversion(const std::string& literal)
{
    ConversionPack pack = newPack();
    long value = std::atol(literal.c_str());

    pack.char_value = static_cast<char>(value);
    pack.is_char_valid = isInRange(value, CHAR_MIN, CHAR_MAX);

    pack.int_value = static_cast<int>(value);
    pack.is_int_valid = (pack.int_value == value);

    pack.float_value = static_cast<float>(value);
    pack.double_value = static_cast<double>(value);

    std::cout << pack << std::endl;
}

void ScalarConverter::floatConversion(const std::string& literal)
{
    ConversionPack pack = newPack();
    float value = std::atof(literal.c_str());

    pack.char_value = static_cast<char>(value);
    pack.is_char_valid = isInRange(value, CHAR_MIN, CHAR_MAX);

    pack.int_value = static_cast<int>(value);
    pack.is_int_valid = isInRange(static_cast<long>(value), INT_MIN, INT_MAX);

    pack.float_value = static_cast<float>(value);
    pack.double_value = static_cast<double>(value);

    std::cout << pack << std::endl;
}

void ScalarConverter::doubleConversion(const std::string& literal)
{
    ConversionPack pack = newPack();
    double value = std::strtod(literal.c_str(), 0);

    pack.char_value = static_cast<char>(value);
    pack.is_char_valid = isInRange(value, CHAR_MIN, CHAR_MAX);

    pack.int_value = static_cast<int>(value);
    pack.is_int_valid = isInRange(static_cast<long>(value), INT_MIN, INT_MAX);

    pack.float_value = static_cast<float>(value);
    pack.double_value = static_cast<double>(value);

    std::cout << pack << std::endl;
}

void ScalarConverter::pseudoLiteralConversion(const std::string& literal)
{
    ConversionPack pack = newPack();
    double value = extractPseudoLiteral(literal);

    pack.char_value = static_cast<char>(value);
    pack.is_char_valid = isInRange(value, CHAR_MIN, CHAR_MAX);

    pack.int_value = static_cast<int>(value);
    pack.is_int_valid = isInRange(static_cast<long>(value), INT_MIN, INT_MAX);

    pack.float_value = static_cast<float>(value);
    pack.double_value = static_cast<double>(value);

    std::cout << pack << std::endl;
}

void ScalarConverter::invalidConversion(const std::string&)
{
    ConversionPack pack = newPack();

    pack.is_char_valid = false;
    pack.is_int_valid = false;
    pack.is_float_valid = false;
    pack.is_double_valid = false;

    std::cout << pack << std::endl;
}

static bool isInRange(long value, long min, long max)
{
    return (value >= min && value <= max);
}

static double extractPseudoLiteral(const std::string& literal)
{
    double value = 0;

    if (literal.find("nan") != std::string::npos)
    {
        value = std::numeric_limits<double>::quiet_NaN();
    }
    else if (literal.find("inf") != std::string::npos)
    {
        value = std::numeric_limits<double>::infinity();
        if (literal[0] == '-')
        {
            value = -value;
        }
    }
    return value;
}
