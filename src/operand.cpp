#include "operand.hpp"
#include <iostream>
#include <exception>
#include <cmath>
#include <iomanip>

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

static int getResPrecision(int lhs, int rhs)
{
    return lhs >= rhs ? lhs : rhs;
}

static void setResPrecision(std::string & str, int precision)
{
    std::size_t floatPoint = str.find('.');
    if (floatPoint != std::string::npos) {
        int endOfDouble = floatPoint + precision;
        str = str.substr(0, endOfDouble);
    }
}

Operand::Operand(eOperandType type, std::string val)
    :_precision(0),
        _type(type),
        _strValue(val)
{
    if (type >= eOperandType::FLOAT) {
        std::string decimals;
        std::size_t floatPoint = val.find('.');
        if (floatPoint != std::string::npos) {
            decimals = val.substr(floatPoint);
            _precision = decimals.size();
        }
    }
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
    int resultPrecision = getResPrecision(getPrecision(), rhs.getPrecision());
    Operand const * rhsOperand = nullptr;
    IOperand const * result = nullptr;
    std::string resultValue;
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
        setResPrecision(resultValue, resultPrecision);
        result = _factory.createOperand(resultType, resultValue);
    }
    return result;
}

IOperand const * Operand::operator-( IOperand const & rhs ) const
{
    eOperandType resultType = getResType(this->getType(), rhs.getType());
    int resultPrecision = getResPrecision(getPrecision(), rhs.getPrecision());
    Operand const * rhsOperand = nullptr;
    IOperand const * result = nullptr;
    std::string resultValue;
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
        setResPrecision(resultValue, resultPrecision);
        result = _factory.createOperand(resultType, resultValue);
    }
    return result;
}

IOperand const * Operand::operator*( IOperand const & rhs ) const
{
    eOperandType resultType = getResType(this->getType(), rhs.getType());
    int resultPrecision = getResPrecision(getPrecision(), rhs.getPrecision());
    Operand const * rhsOperand = nullptr;
    IOperand const * result = nullptr;
    std::string resultValue;
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
        setResPrecision(resultValue, resultPrecision);
        result = _factory.createOperand(resultType, resultValue);
    }
    return result;
}

IOperand const * Operand::operator/( IOperand const & rhs ) const
{
    eOperandType resultType = getResType(this->getType(), rhs.getType());
    int resultPrecision = getResPrecision(getPrecision(), rhs.getPrecision());
    Operand const * rhsOperand = nullptr;
    IOperand const * result = nullptr;
    std::string resultValue;
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
        setResPrecision(resultValue, resultPrecision);
        result = _factory.createOperand(resultType, resultValue);
    }
    return result;
}

IOperand const * Operand::operator%( IOperand const & rhs ) const
{
    eOperandType resultType = getResType(this->getType(), rhs.getType());
    int resultPrecision = getResPrecision(getPrecision(), rhs.getPrecision());
    Operand const * rhsOperand = nullptr;
    IOperand const * result = nullptr;
    std::string resultValue;
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
        setResPrecision(resultValue, resultPrecision);
        result = _factory.createOperand(resultType, resultValue);
        }
    return result;
}


std::string const & Operand::toString( void ) const
{
    return _strValue;
}

