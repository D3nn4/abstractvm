#ifndef _CMD_HPP_
#define _CMD_HPP_

#include "token.hpp"
#include "ioperand.hpp"
#include <map>
#include <vector>
#include <string>
#include <cstdbool>
#include <functional>
#include <memory>

class CmdManager
{
public:

    typedef void (CmdManager::*funcPtr)(std::vector<IOperand const *> & stack, Token token);
    typedef std::function<void (std::vector<IOperand const *> & stack, Token token) > funcObject;
    typedef std::map<Token::CMD, funcObject> cmdByType;

    CmdManager();

    void cmd(std::vector<IOperand const *> & stack, Token token);

private:

    void push   (std::vector<IOperand const *> & stack, Token );
    void pop    (std::vector<IOperand const *> & stack, Token );
    void dump   (std::vector<IOperand const *> & stack, Token );
    void assert (std::vector<IOperand const *> & stack, Token );
    void add    (std::vector<IOperand const *> & stack, Token );
    void sub    (std::vector<IOperand const *> & stack, Token );
    void mult   (std::vector<IOperand const *> & stack, Token );
    void div    (std::vector<IOperand const *> & stack, Token );
    void mod    (std::vector<IOperand const *> & stack, Token );
    void print  (std::vector<IOperand const *> & stack, Token );

    cmdByType cmds;
};

#endif //_CMD_HPP_
