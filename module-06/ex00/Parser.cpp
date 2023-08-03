#include "Parser.hpp"

Parser::Parser()
{
}

ScalarType Parser::parseScalarType(const std::string& literal)
{
    if (!literal.length())
    {
        return UNKNOWN;
    }

    ScalarType type = UNKNOWN;

    type = parseChar(literal);
    if (type != UNKNOWN)
    {
        return type;
    }

    type = parseNumber(literal);
    if (type != UNKNOWN)
    {
        return type;
    }

    type = parsePseudoLiteral(literal);
    if (type != UNKNOWN)
    {
        return type;
    }

    return UNKNOWN;
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
                return UNKNOWN;
            hasDot = true;
        }
        else if (currentChar == 'f' || currentChar == 'F')
        {
            if (hasF)
                return UNKNOWN;
            hasF = true;
        }
        else if (!std::isdigit(currentChar))
        {
            return UNKNOWN;
        }
        idx++;
    }

    if (hasF)
    {
        return FLOAT;
    }
    return hasDot ? DOUBLE : INT;
}

ScalarType Parser::parsePseudoLiteral(const std::string& literal)
{
    if (literal == "nan" || literal == "nanf")
    {
        return PSEUDO;
    }
    if (literal == "inff" || literal == "-inff" || literal == "+inff")
    {
        return PSEUDO;
    }
    else if (literal == "inf" || literal == "-inf" || literal == "+inf")
    {
        return PSEUDO;
    }

    return UNKNOWN;
}
