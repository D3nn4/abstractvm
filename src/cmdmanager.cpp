#include "cmdmanager.hpp"
#include "abstractvm.hpp"
#include <iostream>
#include <algorithm>
#include <exception>

static void fillMap(CmdManager *self, CmdManager::cmdByType& toFill, Token::CMD type, CmdManager::funcPtr cmdFunc)
{
    using namespace std::placeholders;
    CmdManager::funcObject toAdd = std::bind(cmdFunc, self, _1, _2);
    toFill.insert( std::make_pair( type, toAdd));
}

static void displayValue(IOperand const * op)
{
    std::cout << op->toString() << std::endl;
}

CmdManager::CmdManager()
{
    fillMap(this, cmds, Token::CMD::PUSH,   &CmdManager::push);
    fillMap(this, cmds, Token::CMD::POP,    &CmdManager::pop);
    fillMap(this, cmds, Token::CMD::DUMP,   &CmdManager::dump);
    fillMap(this, cmds, Token::CMD::ASSERT, &CmdManager::assert);
    fillMap(this, cmds, Token::CMD::ADD,    &CmdManager::add);
    fillMap(this, cmds, Token::CMD::SUB,    &CmdManager::sub);
    fillMap(this, cmds, Token::CMD::MULT,   &CmdManager::mult);
    fillMap(this, cmds, Token::CMD::DIV,    &CmdManager::div);
    fillMap(this, cmds, Token::CMD::MOD,    &CmdManager::mod);
    fillMap(this, cmds, Token::CMD::PRINT,  &CmdManager::print);
}

void CmdManager::cmd(std::vector<IOperand const *> & stack, Token token)
{
    if(cmds.find(token.cmd) == cmds.end()) {
        throw AbstractVM::Exception("Unknown cmd");
    }
    try
    {
        cmds[token.cmd](stack, token);
    }
    catch(AbstractVM::Exception & e)
    {
        throw e;
    }
}

void CmdManager::push   (std::vector<IOperand const *> & stack, Token token)
{
    if(token.valueOperand != nullptr) {
        stack.push_back(token.valueOperand);
    }
}
void CmdManager::pop    (std::vector<IOperand const *> & stack, Token )
{
    if(!stack.empty()) {
        stack.pop_back();
    }
    else {
        throw AbstractVM::Exception("Empty stack");
    }
}
void CmdManager::dump   (std::vector<IOperand const *> & stack, Token )
{
    if (!stack.empty()) {
        for_each(stack.rbegin(), stack.rend(), displayValue);
    }
}
void CmdManager::assert (std::vector<IOperand const *> & stack, Token token)
{
    if (!stack.empty()){
        IOperand const * lastOnStack = stack.back();
        if(lastOnStack->getType() != token.valueOperand->getType()
           || lastOnStack->toString().compare(token.valueOperand->toString()) != 0) {
            throw AbstractVM::Exception("Wrong assert value");
        }
    }
    else {
        throw AbstractVM::Exception("No value on stack");
    }
}
void CmdManager::add    (std::vector<IOperand const *> & stack, Token )
{
    if (stack.size() > 1) {
        IOperand const * rhs = stack.back();
        stack.pop_back();
        IOperand const * lhs = stack.back();
        stack.pop_back();
        IOperand const * result = *lhs + *rhs;
        if (result == nullptr) {
            throw AbstractVM::Exception("Error on result");
            return;
        }
        stack.push_back(result);
    }
    else {
        throw AbstractVM::Exception("Nothing to add");
    }
}
void CmdManager::sub    (std::vector<IOperand const *> & stack, Token )
{
    if (stack.size() > 1) {
        IOperand const * rhs = stack.back();
        stack.pop_back();
        IOperand const * lhs = stack.back();
        stack.pop_back();
        IOperand const * result = *lhs - *rhs;
        if (result == nullptr) {
            throw AbstractVM::Exception("Error on result");
            return;
        }
        stack.push_back(result);
    }
    else {
        throw AbstractVM::Exception("Nothing to sub");
    }
}
void CmdManager::mult   (std::vector<IOperand const *> & stack, Token )
{
    if (stack.size() > 1) {
        IOperand const * rhs = stack.back();
        stack.pop_back();
        IOperand const * lhs = stack.back();
        stack.pop_back();
        IOperand const * result = *lhs * *rhs;
        if (result == nullptr) {
            throw AbstractVM::Exception("Error on result");
            return;
        }
        stack.push_back(result);
    }
    else {
        throw AbstractVM::Exception("Nothing to mult");
    }
}
void CmdManager::div    (std::vector<IOperand const *> & stack, Token )
{
    if (stack.size() > 1) {
        IOperand const * rhs = stack.back();
        std::cout << rhs->toString() << std::endl;
        if (rhs->toString().compare("0") == 0) {
            throw AbstractVM::Exception("Can't divide by 0");
            return;
        }
        stack.pop_back();
        IOperand const * lhs = stack.back();
        stack.pop_back();
        IOperand const * result = *lhs / *rhs;
        if (result == nullptr) {
            throw AbstractVM::Exception("Error on result");
            return;
        }
        stack.push_back(result);
    }
    else {
        throw AbstractVM::Exception("Nothing to div");
    }
}
void CmdManager::mod    (std::vector<IOperand const *> & stack, Token )
{
    if (stack.size() > 1) {
        IOperand const * rhs = stack.back();
        if (rhs->toString().compare("0") == 0) {
            throw AbstractVM::Exception("Can't divide by 0");
            return;
        } 
        stack.pop_back();
        IOperand const * lhs = stack.back();
        stack.pop_back();
        IOperand const * result = *lhs % *rhs;
        if (result == nullptr) {
            throw AbstractVM::Exception("Error on result");
            return;
        }
        stack.push_back(result);
    }
    else {
        throw AbstractVM::Exception("Nothing to div");
    }
}
void CmdManager::print  (std::vector<IOperand const *> & stack, Token )
{
    IOperand const * toPrint = stack.back();
    if(toPrint->getType() != eOperandType::INT8){
        throw AbstractVM::Exception("Can't print anything other than an int8");
        return;
    }
    int intergerToPrint = std::stoi(toPrint->toString());
    if( '!' <= intergerToPrint && intergerToPrint <= '~' ){
        char charToPrint = intergerToPrint;
        std::cout << charToPrint << std::endl;
    }
}
