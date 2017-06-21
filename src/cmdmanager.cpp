#include "cmdmanager.hpp"


static void fillMap(CmdManager *self, CmdManager::cmdByType& toFill, Token::CMD type, CmdManager::funcPtr cmdFunc)
{
    using namespace std::placeholders;
    CmdManager::funcObject toAdd = std::bind(cmdFunc, self, _1, _2);
    toFill.insert( std::make_pair( type, toAdd));
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
    
}
void CmdManager::pop    (std::vector<IOperand const *> & stack, Token token)
{
    
}
void CmdManager::dump   (std::vector<IOperand const *> & stack, Token token)
{
    
}
void CmdManager::assert (std::vector<IOperand const *> & stack, Token token)
{
    
}
void CmdManager::add    (std::vector<IOperand const *> & stack, Token token)
{
    
}
void CmdManager::sub    (std::vector<IOperand const *> & stack, Token token)
{
    
}
void CmdManager::mult   (std::vector<IOperand const *> & stack, Token token)
{
    
}
void CmdManager::div    (std::vector<IOperand const *> & stack, Token token)
{
    
}
void CmdManager::mod    (std::vector<IOperand const *> & stack, Token token)
{
    
}
void CmdManager::print  (std::vector<IOperand const *> & stack, Token token)
{
    
}
void CmdManager::exit   (std::vector<IOperand const *> & stack, Token token)
{
    
}
