/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversionPack.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 21:51:24 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/08/03 11:05:34 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversionPack.hpp"

std::ostream& operator<<(std::ostream& out, const ConversionPack& pack)
{
    writeCharField(out, pack);
    out << '\n';
    writeIntField(out, pack);

    out << std::fixed << std::setprecision(1) << '\n';

    writeFloatField(out, pack);
    out << '\n';
    writeDoubleField(out, pack);

    return out;
}

ConversionPack newPack()
{
    ConversionPack pack;

    pack.charValue = 0;
    pack.hasValidChar = true;

    pack.intValue = 0;
    pack.hasValidInt = true;

    pack.floatValue = 0;
    pack.hasValidFloat = true;

    pack.doubleValue = 0;
    pack.hasValidDouble = true;

    return pack;
}

void writeCharField(std::ostream& out, const ConversionPack& pack)
{
    out << "char: ";

    if (!pack.hasValidChar)
    {
        out << "impossible";
    }
    else if (std::isprint(pack.charValue))
    {
        out << "'" << pack.charValue << "'";
    }
    else
    {
        out << "Non-displayable";
    }
}

void writeIntField(std::ostream& out, const ConversionPack& pack)
{
    out << "int: ";

    if (pack.hasValidInt)
    {
        out << pack.intValue;
    }
    else
    {
        out << "impossible";
    }
}

void writeFloatField(std::ostream& out, const ConversionPack& pack)
{
    out << "float: ";

    if (pack.hasValidFloat)
    {
        out << pack.floatValue << 'f';
    }
    else
    {
        out << "impossible";
    }
}

void writeDoubleField(std::ostream& out, const ConversionPack& pack)
{
    out << "double: ";

    if (pack.hasValidDouble)
    {
        out << pack.doubleValue;
    }
    else
    {
        out << "impossible";
    }
}
