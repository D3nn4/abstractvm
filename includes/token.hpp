#ifndef _TOKEN_HPP_
#define _TOKEN_HPP_

#include <string>

#include "ioperand.hpp"

struct Token
{
    enum class CMD
        {
            EMPTY,
            COM,
            PUSH,
            POP,
            DUMP,
            ASSERT,
            ADD,
            SUB,
            MULT,
            DIV,
            MOD,
            PRINT,
            EXIT
        };

    CMD cmd = CMD::EMPTY;
    std::string input;
    IOperand const * valueOperand = nullptr;
};

#endif //_TOKEN_HPP_
