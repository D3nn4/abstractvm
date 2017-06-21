#include "factory.hpp"
#include "operand.hpp"
#include "lexer.hpp"
#include "token.hpp"
#include <iostream>

int main()
{
    Factory factory;

    {
        IOperand const * lhs =factory.createOperand(eOperandType::INT8, "42");
        IOperand const * rhs =factory.createOperand(eOperandType::INT8, "2");
        IOperand const * res = *lhs + *rhs;
        std::cout << lhs->toString() << " + " << rhs->toString() << " = " << res->toString() << std::endl;
    }

    std::cout << "\n\n";

    {
        IOperand const * lhs =factory.createOperand(eOperandType::DOUBLE, "42.42");
        IOperand const * rhs =factory.createOperand(eOperandType::INT8, "2");
        IOperand const * res = *lhs * *rhs;
        std::cout << lhs->toString() << " * " << rhs->toString() << " = " << res->toString() << std::endl;
    }

std::cout << "\n\n";

    {
        IOperand const * lhs =factory.createOperand(eOperandType::DOUBLE, "1.5");
        IOperand const * rhs =factory.createOperand(eOperandType::FLOAT, "4.5");
        IOperand const * res = *lhs + *rhs;
        std::cout << lhs->toString() << " + " << rhs->toString() << " = " << res->toString() << std::endl;
    }

    Lexer lexer;
    {
        Token token = lexer.createToken("push int8(2)");
        if(token.valueOperand != nullptr){
            std::cout << "Token with input " << token.input << " has an operand with a value of : " << token.valueOperand->toString() << std::endl;
        }
        else {
            std::cout << "Token with input " << token.input << " has an nullptr " << std::endl;
        }
    }
    {
        Token token = lexer.createToken("push float(8.12)");
        if(token.valueOperand != nullptr){
            std::cout << "Token with input " << token.input << " has an operand with a value of : " << token.valueOperand->toString() << std::endl;
        }
        else {
            std::cout << "Token with input " << token.input << " has an nullptr " << std::endl;
        }
    }

    std::cout << "The End.\n";

return 0;
}
