#include "abstractvm.hpp"
#include <iostream>
#include <exception>
#include <fstream>
#include <sstream>
#include <cstdbool>

void AbstractVM::run(std::string fileName)
{
    std::ifstream infile(fileName);
    std::vector<std::string> entryList;
    std::string line;
    _readOnFile = true;
    while (std::getline(infile, line)) {
        std::istringstream iss(line);
        entryList.push_back(line);
        line.clear();
    }
    bool run = true;
    for(std::string cmd : entryList){
        run = _manageEntry(cmd);
        if(run == false){
            break;
        }
    }
    if(run != false
       && entryList.back().compare("exit") != 0){
        std::cout << "Error : no exit command" << std::endl;
    }
}

void AbstractVM::run()
{
    _readOnFile = false;
    std::vector<std::string> entryList;
    std::string entry;
    bool read = true;
    while(read) {
        std::getline(std::cin, entry);
        if(entry.compare(";;") == 0){
            read = false;
        }
        else{
            entryList.push_back(entry);
        }
        entry.clear();
    }
    bool run = true;
    for(std::string cmd : entryList){
        run = _manageEntry(cmd);
        if(run == false){
            break;
        }
    }
    if(run != false
       && entryList.back().compare("exit") != 0){
        std::cout << "Error : no exit command" << std::endl;
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
        if(token.cmd != Token::CMD::COM) {
            try {
                _cmdManager.cmd(_stack, token);
            }
            catch (Exception & e) {
                std::cout << "error : " << e.what() << std::endl;
                return false;
            }
        }
        return true;
    }
    return false;
}
