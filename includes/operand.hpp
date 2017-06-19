#ifndef _OPERAND_HPP_
#define _OPERAND_HPP_

#include "ioperand.hpp"
#include "factory.hpp"
#include <string>

class Factory;

class Operand : public IOperand
{
public:

    Operand(eOperandType type, std::string val);

    int getPrecision( void ) const override;
    eOperandType getType( void ) const override;

    IOperand const * operator+( IOperand const & rhs ) const override;
    IOperand const * operator-( IOperand const & rhs ) const override;
    IOperand const * operator*( IOperand const & rhs ) const override;
    IOperand const * operator/( IOperand const & rhs ) const override;
    IOperand const * operator%( IOperand const & rhs ) const override;

    std::string const & toString( void ) const override;

    ~Operand( void ) {}

private:

    Factory _factory;
    int _precision;
    eOperandType _type;
    std::string const _strValue;
};

#endif //_OPERAND_HPP_
