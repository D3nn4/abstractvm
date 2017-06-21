#include "abstractvm.hpp"
#include <iostream>

// void AbstractVM::run(std::string fileName)
// {
    
// }

void AbstractVM::run()
{
    std::string entry;

    bool read = true;
    while(read) {
        std::cin >> entry;
        read = _manageEntry(entry);
        entry.clear();
    }
}

bool AbstractVM::_manageEntry(std::string entry)
{
    Token token = _lexer.createToken(entry);
    if(token.cmd == Token::CMD::EMPTY
       || token.cmd == Token::CMD::EXIT) {
        return false;
    }
    return _applyCmd(token);
}

bool AbstractVM::_applyCmd(Token token)
{
     
    return true;
}
