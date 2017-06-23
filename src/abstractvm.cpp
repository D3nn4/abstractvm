#include "abstractvm.hpp"
#include <iostream>
#include <exception>

// void AbstractVM::run(std::string fileName)
// {
    
// }

void AbstractVM::run()
{
    std::string entry;

    bool read = true;
    while(read) {
        std::getline(std::cin, entry);
        read = _manageEntry(entry);
        entry.clear();
    }
}

bool AbstractVM::_manageEntry(std::string entry)
{
    Token token;
    try {
        token = _lexer.createToken(entry);
    }
    catch(Exception & e){
        std::cout << "error : " << e.what() << std::endl;
        return false;
    }
    if(token.cmd == Token::CMD::EXIT) {
        return false;
    }
    return _applyCmd(token);
}

bool AbstractVM::_applyCmd(Token token)
{
    if(token.cmd != Token::CMD::EMPTY
       || token.cmd != Token::CMD::EXIT) {
        try {
            _cmdManager.cmd(_stack, token);
        }
        catch (Exception & e) {
            std::cout << "error : " << e.what() << std::endl;
            return false;
        }
    }
    else {
        return false;
    }
}
