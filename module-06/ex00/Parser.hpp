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

private:
    Parser();
};

#endif // !PARSER_HPP
