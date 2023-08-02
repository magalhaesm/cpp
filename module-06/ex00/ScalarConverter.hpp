/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 13:21:34 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/08/02 17:43:21 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

enum ScalarType
{
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    PSEUDO,
    UNKNOWN
};

class ScalarConverter
{
public:
    static void convert(const std::string& literal);
    static ScalarType parseScalarType(const std::string& data);
    static ScalarType parseChar(const std::string& literal);
    static ScalarType parseNumber(const std::string& literal);
    static ScalarType parsePseudoLiteral(const std::string& literal);

private:
    ScalarConverter();
};

#endif // !SCALARCONVERTER_HPP
