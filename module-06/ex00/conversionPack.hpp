/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversionPack.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 21:51:30 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/08/03 11:03:49 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERVSIONPACK_HPP
#define CONVERVSIONPACK_HPP

#include <string>
#include <iomanip>
#include <ostream>

struct ConversionPack
{
    bool hasValidChar;
    bool hasValidInt;
    bool hasValidFloat;
    bool hasValidDouble;

    char charValue;
    int intValue;
    float floatValue;
    double doubleValue;
};

ConversionPack newPack();
void writeCharField(std::ostream&, const ConversionPack&);
void writeIntField(std::ostream&, const ConversionPack&);
void writeFloatField(std::ostream&, const ConversionPack&);
void writeDoubleField(std::ostream&, const ConversionPack&);

std::ostream& operator<<(std::ostream&, const ConversionPack&);

#endif // !CONVERVSIONPACK_HPP
