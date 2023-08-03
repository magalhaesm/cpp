/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversionPack.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 21:51:24 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/08/02 23:53:28 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversionPack.hpp"

std::ostream& operator<<(std::ostream& out, const ConversionPack& rhs)
{
    writeCharField(out, rhs);
    out << '\n';
    writeIntField(out, rhs);

    out << std::fixed << std::setprecision(1) << '\n';

    writeFloatField(out, rhs);
    out << '\n';
    writeDoubleField(out, rhs);

    return out;
}

ConversionPack newPack()
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

void writeCharField(std::ostream& out, const ConversionPack& rhs)
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

void writeIntField(std::ostream& out, const ConversionPack& rhs)
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

void writeFloatField(std::ostream& out, const ConversionPack& rhs)
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

void writeDoubleField(std::ostream& out, const ConversionPack& rhs)
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
