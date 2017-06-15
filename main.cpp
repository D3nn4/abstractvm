// #include "abstractvm.hpp"
#include "factory.hpp"
#include <iostream>

int main()
{
    Factory factory;

    factory.createOperand(eOperandType::DOUBLE, "42.42");
    std::cout << "The End.\n";

return 0;
}
