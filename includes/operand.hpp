#ifndef _OPERAND_HPP_
#define _OPERAND_HPP_

#include "ioperand.hpp"
#include <string>

template class<T>
class Operand : public IOperand
{
public:

    Operand(T val, int precision, eOperandType type);

    int getPrecision( void ) const override;
    IOperand::eOperandType getType( void ) const override;

    IOperand const * operator+( IOperand const & rhs ) const override;
    IOperand const * operator-( IOperand const & rhs ) const override;
    IOperand const * operator*( IOperand const & rhs ) const override;
    IOperand const * operator/( IOperand const & rhs ) const override;
    IOperand const * operator%( IOperand const & rhs ) const override;

    std::string const & toString( void ) const override;

    ~Operand( void ) {}

    T value;

private:

    int _precision;
    eOperandType _type;
    std::string const _strValue;
};

#endif //_OPERAND_HPP_
