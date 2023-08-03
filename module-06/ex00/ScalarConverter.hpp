/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 13:21:34 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/08/02 21:50:56 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

#include "Parser.hpp"
#include "conversionPack.hpp"

class ScalarConverter
{
public:
    static void convert(const std::string&);

private:
    ScalarConverter();

    typedef void (*func)(const std::string&);
    struct ConversionFunction
    {
        ScalarType type;
        func function;
    };

    static void charConversion(const std::string&);
    static void intConversion(const std::string&);
    static void floatConversion(const std::string&);
    static void doubleConversion(const std::string&);
    static void pseudoLiteralConversion(const std::string&);
    static void invalidConversion(const std::string&);

    static const int functions = 6;
    static const ConversionFunction conversions[functions];
};

#endif // !SCALARCONVERTER_HPP
