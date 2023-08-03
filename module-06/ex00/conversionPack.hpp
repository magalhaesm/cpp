/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversionPack.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 21:51:30 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/08/02 21:52:28 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERVSIONPACK_HPP
#define CONVERVSIONPACK_HPP

#include <string>
#include <iomanip>
#include <ostream>

struct ConversionPack
{
    bool is_char_valid;
    bool is_int_valid;
    bool is_float_valid;
    bool is_double_valid;

    char char_value;
    int int_value;
    float float_value;
    double double_value;
};

ConversionPack newPack();
void charConversionResult(std::ostream&, const ConversionPack&);
void intConversionResult(std::ostream&, const ConversionPack&);
void floatConversionResult(std::ostream&, const ConversionPack&);
void doubleConversionResult(std::ostream&, const ConversionPack&);

std::ostream& operator<<(std::ostream&, const ConversionPack&);

#endif // !CONVERVSIONPACK_HPP
