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
    std::string entry;
    _readOnFile = true;
    while (std::getline(infile, entry)) {
        std::istringstream iss(entry);
        if(!entry.empty()){
            entryList.push_back(entry);
        }
        entry.clear();
    }
    _manageEntry(entryList);
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
        else if(!entry.empty()){
                entryList.push_back(entry);
        }
        entry.clear();
    }
    _manageEntry(entryList);
}

void AbstractVM::_manageEntry(std::vector<std::string> entryList)
{
    int line = 1;
    if(!entryList.empty()){
        try {
            for(std::string cmd : entryList){
                _applyCmd(cmd);
                line++;
            }
            if(entryList.back().compare("exit") != 0){
                throw AbstractVM::Exception("no exit command");
            }
        }
        catch(AbstractVM::Exception & e) {
            std::cout << "Line " << line << " : error : " << e.what() << std::endl;
        }
    }
    else {
        std::cout << "Error : empty program" << std::endl;
    }
}

void AbstractVM::_applyCmd(std::string entry)
{
    Token token;
    token = _lexer.createToken(entry);
    if(token.cmd != Token::CMD::EXIT
       && token.cmd != Token::CMD::COM) {
        _cmdManager.cmd(_stack, token);
    }
}
