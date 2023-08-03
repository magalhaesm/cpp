/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 23:26:17 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/08/02 23:26:18 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_HPP
#define PARSER_HPP

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

class Parser
{
public:
    static ScalarType parseScalarType(const std::string& literal);
    static ScalarType parseChar(const std::string& literal);
    static ScalarType parseNumber(const std::string& literal);
    static ScalarType parsePseudoLiteral(const std::string& literal);

    static const int totalPseudos = 8;
    static const std::string supportedPseudos[totalPseudos];

private:
    Parser();
};

#endif // !PARSER_HPP
