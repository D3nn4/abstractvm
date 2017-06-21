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

    // bool cmd(std::vector<IOperand const *> & stack, Token token);

private:

    void push   (std::vector<IOperand const *> & stack, Token token);
    void pop    (std::vector<IOperand const *> & stack, Token token);
    void dump   (std::vector<IOperand const *> & stack, Token token);
    void assert (std::vector<IOperand const *> & stack, Token token);
    void add    (std::vector<IOperand const *> & stack, Token token);
    void sub    (std::vector<IOperand const *> & stack, Token token);
    void mult   (std::vector<IOperand const *> & stack, Token token);
    void div    (std::vector<IOperand const *> & stack, Token token);
    void mod    (std::vector<IOperand const *> & stack, Token token);
    void print  (std::vector<IOperand const *> & stack, Token token);
    void exit   (std::vector<IOperand const *> & stack, Token token);

    cmdByType cmds;
};

#endif //_CMD_HPP_
