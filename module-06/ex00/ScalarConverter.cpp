/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 13:22:11 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/08/06 00:19:47 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits>
#include <cstdlib>
#include <iostream>

#include "Parser.hpp"
#include "ScalarConverter.hpp"

static double extractPseudoLiteral(const std::string&);

const ScalarConverter::ConversionEntry ScalarConverter::conversionTable[functions] = {
    { CHAR, ScalarConverter::convertToChar },
    { INT, ScalarConverter::convertToInt },
    { FLOAT, ScalarConverter::convertToFloat },
    { DOUBLE, ScalarConverter::convertToDouble },
    { PSEUDO, ScalarConverter::convertToLiteral },
    { UNKNOWN, ScalarConverter::handleInvalidConversion },
};

void ScalarConverter::convert(const std::string& input)
{
    ScalarType type = Parser::parseScalarType(input);
    conversionTable[type].convert(input);
}

void ScalarConverter::convertToChar(const std::string& input)
{
    ConversionPack pack = newPack();
    char value = input[0];

    pack.charValue = value;
    pack.intValue = static_cast<int>(value);
    pack.floatValue = static_cast<float>(value);
    pack.doubleValue = static_cast<double>(value);

    std::cout << pack << std::endl;
}

void ScalarConverter::convertToInt(const std::string& input)
{
    ConversionPack pack = newPack();
    int value = std::atoi(input.c_str());
    long longValue = std::atol(input.c_str());

    pack.charValue = static_cast<char>(value);
    pack.hasValidChar = (pack.charValue == longValue);

    pack.intValue = value;
    pack.hasValidInt = (pack.intValue == longValue);

    pack.floatValue = static_cast<float>(value);
    pack.doubleValue = static_cast<double>(value);

    std::cout << pack << std::endl;
}

void ScalarConverter::convertToFloat(const std::string& input)
{
    ConversionPack pack = newPack();
    float value = std::strtof(input.c_str(), 0);
    long longValue = std::atol(input.c_str());

    pack.charValue = static_cast<char>(value);
    pack.hasValidChar = (pack.charValue == longValue);

    pack.intValue = static_cast<int>(value);
    pack.hasValidInt = (pack.intValue == longValue);

    pack.floatValue = value;
    pack.doubleValue = static_cast<double>(value);

    std::cout << pack << std::endl;
}

void ScalarConverter::convertToDouble(const std::string& input)
{
    ConversionPack pack = newPack();
    double value = std::strtod(input.c_str(), 0);
    long longValue = static_cast<long>(value);

    pack.charValue = static_cast<char>(value);
    pack.hasValidChar = (pack.charValue == longValue);

    pack.intValue = static_cast<int>(value);
    pack.hasValidInt = (pack.intValue == longValue);

    pack.floatValue = static_cast<float>(value);
    pack.doubleValue = value;

    std::cout << pack << std::endl;
}

void ScalarConverter::convertToLiteral(const std::string& input)
{
    ConversionPack pack = newPack();
    double value = extractPseudoLiteral(input);
    long longValue = static_cast<long>(value);

    pack.charValue = static_cast<char>(value);
    pack.hasValidChar = (pack.charValue == longValue);

    pack.intValue = static_cast<int>(value);
    pack.hasValidInt = (pack.intValue == longValue);

    pack.floatValue = static_cast<float>(value);
    pack.doubleValue = value;

    std::cout << pack << std::endl;
}

void ScalarConverter::handleInvalidConversion(const std::string&)
{
    ConversionPack pack = newPack();

    pack.hasValidChar = false;
    pack.hasValidInt = false;
    pack.hasValidFloat = false;
    pack.hasValidDouble = false;

    std::cout << pack << std::endl;
}

static double extractPseudoLiteral(const std::string& input)
{
    double value = 0;

    if (input.find("nan") != std::string::npos)
    {
        value = std::numeric_limits<double>::quiet_NaN();
    }
    else if (input.find("inf") != std::string::npos)
    {
        value = std::numeric_limits<double>::infinity();
        if (input[0] == '-')
        {
            value = -value;
        }
    }
    return value;
}
