#include "factory.hpp"
#include "operand.hpp"

#include <iostream>
#include <string>

class IOperand;

static void fillMap(Factory *self, Factory::ctorByType& toFill, eOperandType type, Factory::funcPtr factoryfunc)
{
    using namespace std::placeholders;
    Factory::funcObject toAdd = std::bind(factoryfunc, self, _1);
    toFill.insert( std::make_pair( type, toAdd));
}
Factory::Factory()
{

    fillMap(this, operandByType, eOperandType::INT8,   &Factory::createInt8);
    fillMap(this, operandByType, eOperandType::INT16,  &Factory::createInt16);
    fillMap(this, operandByType, eOperandType::INT32,  &Factory::createInt32);
    fillMap(this, operandByType, eOperandType::FLOAT,  &Factory::createFloat);
    fillMap(this, operandByType, eOperandType::DOUBLE, &Factory::createDouble);
    std::cout << "factory constructor \n";
}


IOperand const * Factory::createOperand( eOperandType type, std::string const & value ) const
{

    auto it = operandByType.find(type);
    
    if (it != operandByType.end()) {
        auto ctor = it->second;
        return ctor(value);
    }
}

IOperand const * Factory::createInt8( std::string const & value ) const
{
    std::cout << "create Int8 \n";
    return nullptr;
}

IOperand const * Factory::createInt16( std::string const & value ) const
{
    std::cout << "create Int16 \n";
    return nullptr;
}

IOperand const * Factory::createInt32( std::string const & value ) const
{
    std::cout << "create Int32 \n";
    return nullptr;
}

IOperand const * Factory::createFloat( std::string const & value ) const
{
    std::cout << "create Float \n";
    return nullptr;
}

IOperand const * Factory::createDouble( std::string const & value ) const
{
    std::cout << "create Double \n";
    return nullptr;
}
