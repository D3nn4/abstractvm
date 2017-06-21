#ifndef _VM_HPP_
#define _VM_HPP_

#include "lexer.hpp"
#include "cmdmanager.hpp"
#include "token.hpp"
#include "factory.hpp"
#include "ioperand.hpp"
#include <vector>
#include <string>
#include <cstdbool>

class AbstractVM
{
public:

    //void run(std::string fileName) const;
    void run();


private:

    bool _manageEntry(std::string entry);
    bool _applyCmd(Token token);

    Factory _factory;
    Lexer _lexer;
    CmdManager _cmdManager;
    
    std::vector<IOperand const *> _stack;

};

#endif //_VM_HPP_
