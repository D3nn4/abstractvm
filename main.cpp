// #include "abstractvm.hpp"
#include "factory.hpp"
#include "operand.hpp"
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
        IOperand const * res = *lhs + *rhs;
        std::cout << lhs->toString() << " + " << rhs->toString() << " = " << res->toString() << std::endl;
    }

std::cout << "\n\n";

    {
        IOperand const * lhs =factory.createOperand(eOperandType::DOUBLE, "1.5");
        IOperand const * rhs =factory.createOperand(eOperandType::FLOAT, "4.5");
        IOperand const * res = *lhs + *rhs;
        std::cout << lhs->toString() << " + " << rhs->toString() << " = " << res->toString() << std::endl;
    }
    std::cout << "The End.\n";

return 0;
}
