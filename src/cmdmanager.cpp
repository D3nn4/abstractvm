#include "cmdmanager.hpp"
#include <iostream>
#include <algorithm>

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
    fillMap(this, cmds, Token::CMD::EXIT,   &CmdManager::exit);
}

void CmdManager::push   (std::vector<IOperand const *> & stack, Token token)
{
    if(token.valueOperand != nullptr) {
        stack.push_back(token.valueOperand);
    }
    else {
        //TODO trow exception
    }
}
void CmdManager::pop    (std::vector<IOperand const *> & stack, Token token)
{
    if(!stack.empty()) {
        stack.pop_back();
    }
    else {
        //TODO trow exception
    }
}
void CmdManager::dump   (std::vector<IOperand const *> & stack, Token token)
{
    if (!stack.empty()) {
        for_each(stack.rbegin(), stack.rend(), displayValue);
    }
    else {
        //TODO trow exception
    }
}
void CmdManager::assert (std::vector<IOperand const *> & stack, Token token)
{
    if (!stack.empty()){
        IOperand const * lastOnStack = stack.back();
        if(lastOnStack->getType() != token.valueOperand->getType()
           || lastOnStack->toString().compare(token.valueOperand->toString()) != 0) {
            //TODO trow exception
        }
    }
    else {
        //TODO trow exception
    }
}
void CmdManager::add    (std::vector<IOperand const *> & stack, Token token)
{
    if (stack.size() > 1) {
        IOperand const * rhs = stack.back();
        stack.pop_back();
        IOperand const * lhs = stack.back();
        stack.pop_back();
        IOperand const * result = *lhs + *rhs;
        if (result == nullptr) {
            //TODO trow exception 
        }
        stack.push_back(result);
    }
    else {
        //TODO trow exception
    }
}
void CmdManager::sub    (std::vector<IOperand const *> & stack, Token token)
{
    if (stack.size() > 1) {
        IOperand const * rhs = stack.back();
        stack.pop_back();
        IOperand const * lhs = stack.back();
        stack.pop_back();
        IOperand const * result = *lhs - *rhs;
        if (result == nullptr) {
            //TODO trow exception 
        }
        stack.push_back(result);
    }
    else {
        //TODO trow exception
    }
}
void CmdManager::mult   (std::vector<IOperand const *> & stack, Token token)
{
    if (stack.size() > 1) {
        IOperand const * rhs = stack.back();
        stack.pop_back();
        IOperand const * lhs = stack.back();
        stack.pop_back();
        IOperand const * result = *lhs * *rhs;
        if (result == nullptr) {
            //TODO trow exception 
        }
        stack.push_back(result);
    }
    else {
        //TODO trow exception
    }
}
void CmdManager::div    (std::vector<IOperand const *> & stack, Token token)
{
    if (stack.size() > 1) {
        IOperand const * rhs = stack.back();
        stack.pop_back();
        IOperand const * lhs = stack.back();
        stack.pop_back();
        IOperand const * result = *lhs / *rhs;
        if (result == nullptr) {
            //TODO trow exception 
        }
        stack.push_back(result);
    }
    else {
        //TODO trow exception
    }
}
void CmdManager::mod    (std::vector<IOperand const *> & stack, Token token)
{
    if (stack.size() > 1) {
        IOperand const * rhs = stack.back();
        stack.pop_back();
        IOperand const * lhs = stack.back();
        stack.pop_back();
        IOperand const * result = *lhs % *rhs;
        if (result == nullptr) {
            //TODO trow exception 
        }
        stack.push_back(result);
    }
    else {
        //TODO trow exception
    }
}
void CmdManager::print  (std::vector<IOperand const *> & stack, Token token)
{
    
}
void CmdManager::exit   (std::vector<IOperand const *> & stack, Token token)
{
    
}
