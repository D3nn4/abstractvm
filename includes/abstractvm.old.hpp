#ifndef _VM_HPP_
#define _VM_HPP_

#include <vector>
#include <string>
#include "ioperand.hpp"


class AbstractVM
{
public:

    void push(std::string & value);
    void pop();
    void dump() const;
    void assert(std::string & value) const;
    void add();
    void sub();
    void mult();
    void div();
    void mod();
    void print() const;
    void exit();

private:

    Factory _factory;
    std::vector<IOperand const * > _stack;

};

#endif //_VM_HPP_
