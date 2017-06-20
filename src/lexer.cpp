#include "lexer.hpp"
#include <boost/algorithm/string.hpp>

Lexer::Lexer()
{
    _getCmdToken = {
        {"",      Token::CMD::EMPTY},
        {";",      Token::CMD::COM},
        {"push",   Token::CMD::PUSH},
        {"pop",    Token::CMD::POP},
        {"dump",   Token::CMD::DUMP},
        {"assert", Token::CMD::ASSERT},
        {"add",    Token::CMD::ADD},
        {"sub",    Token::CMD::SUB},
        {"mult",   Token::CMD::MULT},
        {"div",    Token::CMD::DIV},
        {"mod",    Token::CMD::MOD},
        {"print",  Token::CMD::PRINT},
        {"exit",   Token::CMD::EXIT}
    };

    _getOperandType = {
        {"int8",   eOperandType::INT8},
        {"int16",  eOperandType::INT16},
        {"int32",  eOperandType::INT32},
        {"float",  eOperandType::FLOAT},
        {"double", eOperandType::DOUBLE}
    };
}

Token Lexer::createToken(std::string str)
{
    std::vector<std::string> cmdAndValue;
    boost::split(cmdAndValue,str,boost::is_any_of(" "));
    Token newToken = _fillToken(cmdAndValue);
    newToken.input = str;
    return newToken;
}

Token Lexer::_fillToken(std::vector<std::string> cmdAndValue)
{
    Token token;
    if(!cmdAndValue.empty()) {
        std::string cmdStr = cmdAndValue[0];
        auto cmdIt = _getCmdToken.find(cmdStr);
        if( cmdIt != _getCmdToken.end()){
            token.cmd = cmdIt->second;
            if(cmdAndValue.size() == 2
               && (token.cmd == Token::CMD::PUSH
                   || token.cmd == Token::CMD::ASSERT)) {
                std::string valueStr = cmdAndValue[1];
                std::string valueType = _getValueType(valueStr);
                std::string value = _getValue(valueStr);
                auto typeIt = _getOperandType.find(valueType);
                if( typeIt != _getOperandType.end()){
                    token.valueOperand = _factory.createOperand(typeIt->second, value);
                }
            }
        }
    }
    return token;
}

std::string Lexer::_getValueType(std::string string)
{
    std::string valueType;
    size_t lengthValue = string.find('(') - 1; // -1 to get rid of '('
    if(lengthValue != std::string::npos) {
        valueType = string.substr(0, lengthValue);
    }
    return valueType;
}

std::string Lexer::_getValue(std::string string)
{
    std::string value;
    size_t begin = string.find('(') + 1; // +1 to get rid of '('
    size_t end = string.find(')'); 
    if(begin != std::string::npos
       && end != std::string::npos) {
        value = string.substr(0, end - begin);
    }
    return value;
}
