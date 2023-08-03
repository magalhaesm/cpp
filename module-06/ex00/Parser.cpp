/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 23:26:12 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/08/03 00:02:42 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.hpp"

Parser::Parser()
{
}

const std::string Parser::supportedPseudos[totalPseudos] = {
    "inff", "-inff", "+inff", "nanf", "inf", "-inf", "+inf", "nan"
};

ScalarType Parser::parseScalarType(const std::string& literal)
{
    if (literal.empty())
    {
        return UNKNOWN;
    }

    ScalarType type = parseChar(literal);
    if (type != UNKNOWN)
    {
        return type;
    }

    type = parseNumber(literal);
    if (type != UNKNOWN)
    {
        return type;
    }

    return parsePseudoLiteral(literal);
}

ScalarType Parser::parseChar(const std::string& literal)
{
    if (literal.length() == 1 && !std::isdigit(literal[0]))
    {
        return CHAR;
    }
    return UNKNOWN;
}

static bool isSign(char c)
{
    return c == '+' || c == '-';
}

ScalarType Parser::parseNumber(const std::string& literal)
{
    bool hasDot = false;
    bool hasF = false;

    size_t idx = 0;

    if (isSign(literal[idx]))
    {
        ++idx;
    }

    size_t length = literal.length();
    while (idx < length)
    {
        char currentChar = literal[idx];

        if (currentChar == '.')
        {
            if (hasDot)
            {
                return UNKNOWN;
            }
            hasDot = true;
        }
        else if (currentChar == 'f' || currentChar == 'F')
        {
            if (hasF)
            {
                return UNKNOWN;
            }
            hasF = true;
        }
        else if (!std::isdigit(currentChar))
        {
            return UNKNOWN;
        }
        idx++;
    }

    return hasF ? FLOAT : (hasDot ? DOUBLE : INT);
}

ScalarType Parser::parsePseudoLiteral(const std::string& literal)
{
    for (int idx = 0; idx < totalPseudos; ++idx)
    {
        if (literal == supportedPseudos[idx])
        {
            return PSEUDO;
        }
    }
    return UNKNOWN;
}
