/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AConversionStrategy.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 12:25:23 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/08/02 18:34:22 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <climits>
#include <iostream>
#include <iomanip>
#include <sstream>

#include "AConversionStrategy.hpp"

void charConversionResult(std::ostream& out, const ConversionPack& rhs);
void intConversionResult(std::ostream& out, const ConversionPack& rhs);
void floatConversionResult(std::ostream& out, const ConversionPack& rhs);
void doubleConversionResult(std::ostream& out, const ConversionPack& rhs);

AConversionStrategy::AConversionStrategy()
{
}

AConversionStrategy::AConversionStrategy(const AConversionStrategy& copy)
{
    *this = copy;
}

AConversionStrategy& AConversionStrategy::operator=(const AConversionStrategy&)
{
    return *this;
}

AConversionStrategy::~AConversionStrategy()
{
}

std::ostream& operator<<(std::ostream& out, const ConversionPack& rhs)
{
    charConversionResult(out, rhs);
    out << '\n';
    intConversionResult(out, rhs);

    out << std::fixed << std::setprecision(1) << '\n';

    floatConversionResult(out, rhs);
    out << '\n';
    doubleConversionResult(out, rhs);

    return out;
}

void charConversionResult(std::ostream& out, const ConversionPack& rhs)
{
    out << "char: ";

    if (!rhs.is_char_valid)
    {
        out << "impossible";
    }
    else if (std::isprint(rhs.char_value))
    {
        out << "'" << rhs.char_value << "'";
    }
    else
    {
        out << "Non-displayable";
    }
}

void intConversionResult(std::ostream& out, const ConversionPack& rhs)
{
    out << "int: ";

    if (rhs.is_int_valid)
    {
        out << rhs.int_value;
    }
    else
    {
        out << "impossible";
    }
}

void floatConversionResult(std::ostream& out, const ConversionPack& rhs)
{
    out << "float: ";

    if (rhs.is_float_valid)
    {
        out << rhs.float_value << 'f';
    }
    else
    {
        out << "impossible";
    }
}

void doubleConversionResult(std::ostream& out, const ConversionPack& rhs)
{
    out << "double: ";

    if (rhs.is_double_valid)
    {
        out << rhs.double_value;
    }
    else
    {
        out << "impossible";
    }
}
