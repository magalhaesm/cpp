/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 13:22:11 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/08/03 10:56:19 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits>
#include <cstdlib>
#include <iostream>

#include "Parser.hpp"
#include "ScalarConverter.hpp"

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
    conversionTable[type].convert(literal);
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
    int value = std::atoi(literal.c_str());
    long longValue = std::atol(literal.c_str());

    pack.char_value = static_cast<char>(value);
    pack.is_char_valid = (pack.char_value == longValue);

    pack.int_value = value;
    pack.is_int_valid = (pack.int_value == longValue);

    pack.float_value = static_cast<float>(value);
    pack.double_value = static_cast<double>(value);

    std::cout << pack << std::endl;
}

void ScalarConverter::floatConversion(const std::string& literal)
{
    ConversionPack pack = newPack();
    float value = std::atof(literal.c_str());
    long longValue = std::atol(literal.c_str());

    pack.char_value = static_cast<char>(value);
    pack.is_char_valid = (pack.char_value == longValue);

    pack.int_value = static_cast<int>(value);
    pack.is_int_valid = (pack.int_value == longValue);

    pack.float_value = value;
    pack.double_value = static_cast<double>(value);

    std::cout << pack << std::endl;
}

void ScalarConverter::doubleConversion(const std::string& literal)
{
    ConversionPack pack = newPack();
    double value = std::strtod(literal.c_str(), 0);
    long longValue = static_cast<long>(value);

    pack.char_value = static_cast<char>(value);
    pack.is_char_valid = (pack.char_value == longValue);

    pack.int_value = static_cast<int>(value);
    pack.is_int_valid = (pack.int_value == longValue);

    pack.float_value = static_cast<float>(value);
    pack.double_value = value;

    std::cout << pack << std::endl;
}

void ScalarConverter::pseudoLiteralConversion(const std::string& literal)
{
    ConversionPack pack = newPack();
    double value = extractPseudoLiteral(literal);
    long longValue = static_cast<long>(value);

    pack.char_value = static_cast<char>(value);
    pack.is_char_valid = (pack.char_value == longValue);

    pack.int_value = static_cast<int>(value);
    pack.is_int_valid = (pack.int_value == longValue);

    pack.float_value = static_cast<float>(value);
    pack.double_value = value;

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
