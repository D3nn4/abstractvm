#include "abstractvm.hpp"
#include <iostream>
#include <exception>
#include <fstream>
#include <sstream>

void AbstractVM::run(std::string fileName)
{
    std::ifstream infile(fileName);
    std::string line;
    _readOnFile = true;
    while (std::getline(infile, line)) {
        std::istringstream iss(line);
        _manageEntry(line);
        line.clear();
    }
}

void AbstractVM::run()
{
    _readOnFile = false;
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
    return true;
}
