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
#include <exception>

class AbstractVM
{
public:

    void run(std::string fileName);
    void run();

    //////////////exception
    class Exception : public std::exception
    {
    public:

        Exception(std::string msg) :_msg(msg){}
        virtual const char* what() const throw (){
            return _msg.c_str();
        }
    private:

        std::string _msg;
    };
    //////////////

private:

    bool _manageEntry(std::string entry);
    bool _applyCmd(Token token);

    Factory _factory;
    Lexer _lexer;
    CmdManager _cmdManager;

    bool _readOnFile;

    std::vector<IOperand const *> _stack;

};

#endif //_VM_HPP_
