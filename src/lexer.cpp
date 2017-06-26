#include "lexer.hpp"
#include "abstractvm.hpp"
#include <iostream>
#include <boost/algorithm/string.hpp>
#include <exception>

// static void checkIfProperType(eOperandType givenType, std::string value)
// {
    
// }
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
    Token newToken;
    if(str.empty()){
        throw AbstractVM::Exception("No input");
    }
    else {
        str = _deleteComments(str);
        if(str.empty()) {
            newToken.cmd = Token::CMD::COM;
        }
        else {
            std::vector<std::string> cmdAndValue;
            boost::split(cmdAndValue,str,boost::is_any_of(" "));
            newToken = _fillToken(cmdAndValue);
            newToken.input = str;
        }
    }
    return newToken;
}

std::string Lexer::_deleteComments(std::string str)
{
    size_t semiColon = str.find(';');
    if(semiColon != std::string::npos){
        str = str.substr(0, semiColon);
    }
    return str;
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
                try {
                    std::string value = _getValue(valueStr);
                    auto typeIt = _getOperandType.find(valueType);
                    if( typeIt != _getOperandType.end()){
                        token.valueOperand = _factory.createOperand(typeIt->second, value);
                    }
                }
                catch(AbstractVM::Exception & e){
                    std::cout << "Error :" << e.what() << std::endl;
                    token.cmd = Token::CMD::EXIT;
                }
            }
        }
    }
    return token;
}

std::string Lexer::_getValueType(std::string string)
{
    std::string valueType;
    size_t lengthValue = string.find('(');
    if(lengthValue != std::string::npos) {
        valueType = string.substr(0, lengthValue);
    }
    return valueType;
}

std::string Lexer::_getValue(std::string string)
{
    std::string value;
    size_t begin = string.find('(') + 1; // +1 to get rid of '('
    size_t end = string.size() - 1;
    if(begin != std::string::npos
       && end != std::string::npos) {
        value = string.substr(begin, end - begin);
    }
    bool has_only_digits = (value.find_first_not_of( "0123456789." ) == std::string::npos);
    if(has_only_digits == false) {
        std::cout << "Invalid value : \"" << value << "\"" << std::endl;
        throw AbstractVM::Exception("Invalid value");
    }
    return value;
}
