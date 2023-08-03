/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 13:22:11 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/08/03 16:31:31 by mdias-ma         ###   ########.fr       */
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

    pack.charValue = value;
    pack.intValue = static_cast<int>(value);
    pack.floatValue = static_cast<float>(value);
    pack.doubleValue = static_cast<double>(value);

    std::cout << pack << std::endl;
}

void ScalarConverter::intConversion(const std::string& literal)
{
    ConversionPack pack = newPack();
    int value = std::atoi(literal.c_str());
    long longValue = std::atol(literal.c_str());

    pack.charValue = static_cast<char>(value);
    pack.hasValidChar = (pack.charValue == longValue);

    pack.intValue = value;
    pack.hasValidInt = (pack.intValue == longValue);

    pack.floatValue = static_cast<float>(value);
    pack.doubleValue = static_cast<double>(value);

    std::cout << pack << std::endl;
}

void ScalarConverter::floatConversion(const std::string& literal)
{
    ConversionPack pack = newPack();
    float value = std::strtof(literal.c_str(), 0);
    long longValue = std::atol(literal.c_str());

    pack.charValue = static_cast<char>(value);
    pack.hasValidChar = (pack.charValue == longValue);

    pack.intValue = static_cast<int>(value);
    pack.hasValidInt = (pack.intValue == longValue);

    pack.floatValue = value;
    pack.doubleValue = static_cast<double>(value);

    std::cout << pack << std::endl;
}

void ScalarConverter::doubleConversion(const std::string& literal)
{
    ConversionPack pack = newPack();
    double value = std::strtod(literal.c_str(), 0);
    long longValue = static_cast<long>(value);

    pack.charValue = static_cast<char>(value);
    pack.hasValidChar = (pack.charValue == longValue);

    pack.intValue = static_cast<int>(value);
    pack.hasValidInt = (pack.intValue == longValue);

    pack.floatValue = static_cast<float>(value);
    pack.doubleValue = value;

    std::cout << pack << std::endl;
}

void ScalarConverter::pseudoLiteralConversion(const std::string& literal)
{
    ConversionPack pack = newPack();
    double value = extractPseudoLiteral(literal);
    long longValue = static_cast<long>(value);

    pack.charValue = static_cast<char>(value);
    pack.hasValidChar = (pack.charValue == longValue);

    pack.intValue = static_cast<int>(value);
    pack.hasValidInt = (pack.intValue == longValue);

    pack.floatValue = static_cast<float>(value);
    pack.doubleValue = value;

    std::cout << pack << std::endl;
}

void ScalarConverter::invalidConversion(const std::string&)
{
    ConversionPack pack = newPack();

    pack.hasValidChar = false;
    pack.hasValidInt = false;
    pack.hasValidFloat = false;
    pack.hasValidDouble = false;

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
