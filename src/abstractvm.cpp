#include <string>
#include <iostream>
#include "abstractvm.hpp"


void AbstractVM::run()
{
    getInput();
}

void AbstractVM::getInput()
{
    std::string buffer;
    bool read = true;
    while(read){
        std::getline(std::cin,buffer);
        std::cout << "buffer: "<< buffer << std::endl;
        buffer.erase(buffer.begin(), buffer.end());
    }
}
