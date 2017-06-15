#ifndef _FACTORY_HPP_
#define _FACTORY_HPP_

#include <string>
#include <map>
#include <functional>

#include "operand.hpp"


class Factory
{
public:
    
    typedef IOperand const * (Factory::*funcPtr)(std::string const &) const;
    typedef std::function<IOperand const * (std::string const &) > funcObject;
    typedef std::map<eOperandType, funcObject> ctorByType;


    // struct TypeCompare
    // {
    //     std::size_t operator()(Factory::eOperandType type) const{
    //         return static_cast<std::size_t>(type);
    //     }
    // };

    Factory();
    IOperand const * createOperand( eOperandType type, std::string const & value ) const;
    
private:

    IOperand const * createInt8( std::string const & value ) const;
    IOperand const * createInt16( std::string const & value ) const;
    IOperand const * createInt32( std::string const & value ) const;
    IOperand const * createFloat( std::string const & value ) const;
    IOperand const * createDouble( std::string const & value ) const;

     ctorByType operandByType;
};

#endif //_FACTORY_HPP_
