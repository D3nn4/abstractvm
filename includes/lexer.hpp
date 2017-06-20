#ifndef _LEXER_HPP_
#define _LEXER_HPP_

#include "token.hpp"
#include "factory.hpp"
#include <map>
#include <vector>

class Lexer
{
public:

    Lexer();
    Token createToken(std::string str);

private:

    Token _fillToken(std::vector<std::string> _cmdAndValue);
    std::string _getValueType(std::string string);
    std::string _getValue(std::string string);

    std::map<std::string, Token::CMD> _getCmdToken;
    std::map<std::string, eOperandType> _getOperandType;
    Factory _factory;

};

#endif //_LEXER_HPP_
