/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 13:21:34 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/08/13 18:19:09 by mdias-ma         ###   ########.fr       */
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
    static void convert(const std::string& input);

private:
    ScalarConverter();

    typedef void (*funcPtr)(const std::string& input);
    struct ConversionEntry
    {
        ScalarType type;
        funcPtr convert;
    };

    static void convertToChar(const std::string& input);
    static void convertToInt(const std::string& input);
    static void convertToFloat(const std::string& input);
    static void convertToDouble(const std::string& input);
    static void convertToLiteral(const std::string& input);
    static void handleInvalidConversion(const std::string& input);

    static const int functions = 6;
    static const ConversionEntry conversionTable[functions];
};

#endif // !SCALARCONVERTER_HP
