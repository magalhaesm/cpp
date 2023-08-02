/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AConversionStrategy.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 12:26:01 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/08/02 19:07:37 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <limits>

#include "AConversionStrategy.hpp"
#include "ConversionStrategy.hpp"

static ConversionPack newPack();
static bool isInRange(long value, long min, long max);
static double extractPseudoLiteral(const std::string& literal);

void CharConversionStrategy::convert(const std::string& literal) const
{
    ConversionPack pack = newPack();
    char value = literal[0];

    pack.char_value = value;
    pack.int_value = static_cast<int>(value);
    pack.float_value = static_cast<float>(value);
    pack.double_value = static_cast<double>(value);

    std::cout << pack << std::endl;
}

void IntConversionStrategy::convert(const std::string& literal) const
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

void FloatConversionStrategy::convert(const std::string& literal) const
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

void DoubleConversionStrategy::convert(const std::string& literal) const
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

void PseudoLiteralConversionStrategy::convert(const std::string& literal) const
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

void InvalidConversionStrategy::convert(const std::string&) const
{
    ConversionPack pack = newPack();

    pack.is_char_valid = false;
    pack.is_int_valid = false;
    pack.is_float_valid = false;
    pack.is_double_valid = false;

    std::cout << pack << std::endl;
}

static ConversionPack newPack()
{
    ConversionPack pack;

    pack.char_value = 0;
    pack.is_char_valid = true;

    pack.int_value = 0;
    pack.is_int_valid = true;

    pack.float_value = 0;
    pack.is_float_valid = true;

    pack.double_value = 0;
    pack.is_double_valid = true;

    return pack;
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
        if (literal[0] == '-')
            value = -std::numeric_limits<double>::quiet_NaN();
        else
            value = std::numeric_limits<double>::quiet_NaN();
    }
    else if (literal.find("inf") != std::string::npos)
    {
        if (literal[0] == '-')
            value = -std::numeric_limits<double>::infinity();
        else
            value = std::numeric_limits<double>::infinity();
    }

    return value;
}
