#include "operand.hpp"
#include <iostream>

static eOperandType getResType(eOperandType lhs, eOperandType rhs)
{
    if (lhs == rhs){
        return lhs;
    }
    else if (lhs < rhs && rhs <= eOperandType::INT32
        ||lhs > rhs && lhs <= eOperandType::INT32 ){
        return eOperandType::INT32;
    }
    else {
        return eOperandType::DOUBLE;
    }
}

Operand::Operand(T val)
    :value(val),
     _precision(precision),
     _type(type),
     _strValue(std::to_string(value)){}

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
    eOperandType resultType = getResType(this->getType(), rhs->getType());
    int resultPrecision = 0;
    Operand const & rhsOperand = static_cast<Operand const &>(rhs);
    IOperand * result = nullptr;
    if(resultType < eOperandType::FLOAT){
        long long int total = value + rhsOperand.value;
        result = new Operand<long long int>(total, resultPrecision, resultType);
    }
    else{
        resultPrecision = getResPrecision(this->getPrecision(), rhs->getPrecision());
        long double total = value + rhsOperand.value;
        result = new Operand<long double>(total, resultPrecision, resultType);
    }
    return result;
}

// IOperand const * Operand::operator-( IOperand const & rhs ) const
// {
//     Operand const & rhs8 = static_cast<Operand const &>(rhs);
//     float total = value - rhs8.value;
//     IOperand * result = new Operand(total);
//     return result;
// }

// IOperand const * Operand::operator*( IOperand const & rhs ) const
// {
//     Operand const & rhs8 = static_cast<Operand const &>(rhs);
//     float total = value * rhs8.value;
//     IOperand * result = new Operand(total);
//     return result;
// }

// IOperand const * Operand::operator/( IOperand const & rhs ) const
// {
//     Operand const & rhs8 = static_cast<Operand const &>(rhs);
//     float total = value / rhs8.value;
//     IOperand * result = new Operand(total);
//     return result;
// }

// IOperand const * Operand::operator%( IOperand const & rhs ) const
// {
//     Operand const & rhs8 = static_cast<Operand const &>(rhs);
//     float total = value % rhs8.value;
//     IOperand * result = new Operand(total);
//     return result;
// }

std::string const & Operand::toString( void ) const
{
    return _strValue;
}
