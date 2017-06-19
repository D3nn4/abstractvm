#include "operand.hpp"
#include <iostream>
#include <exception>
#include <cmath>

static eOperandType getResType(eOperandType lhs, eOperandType rhs)
{
    if (lhs == rhs){
        return lhs;
    }
    else if ((lhs < rhs && rhs <= eOperandType::INT32)
        ||(lhs > rhs && lhs <= eOperandType::INT32) ){
        return eOperandType::INT32;
    }
    else {
        return eOperandType::DOUBLE;
    }
};

Operand::Operand(eOperandType type, std::string val)
    :_type(type),
     _strValue(val)
{
    // TODO get precision !!!
}

int Operand::getPrecision( void ) const
{
    return _precision;
}

eOperandType Operand::getType( void ) const
{
    return _type;
}

IOperand const * Operand::operator+( IOperand const & rhs ) const
{
    eOperandType resultType = getResType(this->getType(), rhs.getType());
    Operand const * rhsOperand = nullptr;
    IOperand const * result = nullptr;
    std::string resultValue;
    try {
        rhsOperand = static_cast<Operand const *>(&rhs);

        if(rhsOperand != nullptr){
            if(resultType < eOperandType::FLOAT){
                long long int numericalLhs = std::stoll(toString());
                long long int numericalRhs = std::stoll(rhsOperand->toString());
                long long int numericalTotal = numericalLhs + numericalRhs;
                resultValue = std::to_string(numericalTotal);
            }
            else{
                long double numericalLhs = std::stold(toString());
                long double numericalRhs = std::stold(rhsOperand->toString());
                long double numericalTotal = numericalLhs + numericalRhs;
                resultValue = std::to_string(numericalTotal);
            }
            result = _factory.createOperand(resultType, resultValue);

        }

    }
    catch(const std::exception& e) {
        std::cout << "Error cast " << e.what() << std::endl;
    }
    
    return result;
}

IOperand const * Operand::operator-( IOperand const & rhs ) const
{
    eOperandType resultType = getResType(this->getType(), rhs.getType());
    Operand const * rhsOperand = nullptr;
    IOperand const * result = nullptr;
    std::string resultValue;
    try {
        rhsOperand = static_cast<Operand const *>(&rhs);

        if(rhsOperand != nullptr){
            if(resultType < eOperandType::FLOAT){
                long long int numericalLhs = std::stoll(toString());
                long long int numericalRhs = std::stoll(rhsOperand->toString());
                long long int numericalTotal = numericalLhs - numericalRhs;
                resultValue = std::to_string(numericalTotal);
            }
            else{
                long double numericalLhs = std::stold(toString());
                long double numericalRhs = std::stold(rhsOperand->toString());
                long double numericalTotal = numericalLhs - numericalRhs;
                resultValue = std::to_string(numericalTotal);
            }
            result = _factory.createOperand(resultType, resultValue);
        }

    }
    catch(const std::exception& e) {
        std::cout << "Error cast " << e.what() << std::endl;
    }
    return result;
}

IOperand const * Operand::operator*( IOperand const & rhs ) const
{
    eOperandType resultType = getResType(this->getType(), rhs.getType());
    Operand const * rhsOperand = nullptr;
    IOperand const * result = nullptr;
    std::string resultValue;
    try {
        rhsOperand = static_cast<Operand const *>(&rhs);

        if(rhsOperand != nullptr){
            if(resultType < eOperandType::FLOAT){
                long long int numericalLhs = std::stoll(toString());
                long long int numericalRhs = std::stoll(rhsOperand->toString());
                long long int numericalTotal = numericalLhs * numericalRhs;
                resultValue = std::to_string(numericalTotal);
            }
            else{
                long double numericalLhs = std::stold(toString());
                long double numericalRhs = std::stold(rhsOperand->toString());
                long double numericalTotal = numericalLhs * numericalRhs;
                resultValue = std::to_string(numericalTotal);
            }
            result = _factory.createOperand(resultType, resultValue);
        }

    }
    catch(const std::exception& e) {
        std::cout << "Error cast " << e.what() << std::endl;
    }
    return result;
}

IOperand const * Operand::operator/( IOperand const & rhs ) const
{
    eOperandType resultType = getResType(this->getType(), rhs.getType());
    Operand const * rhsOperand = nullptr;
    IOperand const * result = nullptr;
    std::string resultValue;
    try {
        rhsOperand = static_cast<Operand const *>(&rhs);

        if(rhsOperand != nullptr){
            if(resultType < eOperandType::FLOAT){
                long long int numericalLhs = std::stoll(toString());
                long long int numericalRhs = std::stoll(rhsOperand->toString());
                long long int numericalTotal = numericalLhs / numericalRhs;
                resultValue = std::to_string(numericalTotal);
            }
            else{
                long double numericalLhs = std::stold(toString());
                long double numericalRhs = std::stold(rhsOperand->toString());
                long double numericalTotal = numericalLhs / numericalRhs;
                resultValue = std::to_string(numericalTotal);
            }
            result = _factory.createOperand(resultType, resultValue);
        }

    }
    catch(const std::exception& e) {
        std::cout << "Error cast " << e.what() << std::endl;
    }
    return result;
}

IOperand const * Operand::operator%( IOperand const & rhs ) const
{
    eOperandType resultType = getResType(this->getType(), rhs.getType());
    Operand const * rhsOperand = nullptr;
    IOperand const * result = nullptr;
    std::string resultValue;
    try {
        rhsOperand = static_cast<Operand const *>(&rhs);

        if(rhsOperand != nullptr){
            if(resultType < eOperandType::FLOAT){
                long long int numericalLhs = std::stoll(toString());
                long long int numericalRhs = std::stoll(rhsOperand->toString());
                long long int numericalTotal = numericalLhs % numericalRhs;
                resultValue = std::to_string(numericalTotal);
            }
            else{
                long double numericalLhs = std::stold(toString());
                long double numericalRhs = std::stold(rhsOperand->toString());
                long double numericalTotal = fmod(numericalLhs, numericalRhs);
                resultValue = std::to_string(numericalTotal);
            }
            result = _factory.createOperand(resultType, resultValue);
        }

    }
    catch(const std::exception& e) {
        std::cout << "Error cast " << e.what() << std::endl;
    }
    return result;
}

std::string const & Operand::toString( void ) const
{
    return _strValue;
}

