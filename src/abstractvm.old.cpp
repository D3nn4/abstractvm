#include <iostream>
#include <algorithm>
#include "abstractvm.hpp"

static void displayValue(IOperand const * op)
{
    std::cout << op->toString() << std::endl;
}

void AbstractVM::push(std::string & value)
{
    IOperand const * newOperand = nullptr;
    //creation IOperand a partir de token done with string input
    if (newOperand != nullptr) {
        _stack.push_back(newOperand);
    }
    else {
        // throw exception on creation of new operand and quit app
    }
}

void AbstractVM::pop()
{
    if (!_stack.empty()) {
        _stack.pop_back();
    }
    else {
        //trow exception empty stack and quit app
    }
}

void AbstractVM::dump() const
{
    if (!_stack.empty()) {
        for_each(_stack.rbegin(), _stack.rend(), displayValue);
    }
}

void AbstractVM::assert(std::string & value) const
{
    if(!_stack.empty()) {
        //get token from string
        IOperand const * toCompare = _stack.back();
        //if eOperandType and value NOT the same
        //stop app with error exception
    }
    else {
        //trow exception empty stack and quit app
    }
}

void AbstractVM::add()
{
    if (!_stack.empty() && _stack.size() >= 2){
        IOperand const * lhs = _stack.back();
        _stack.pop_back();
        IOperand const * rhs = _stack.back();
        _stack.pop_back();
        IOperand const * result = *lhs + *rhs;
        if (result == nullptr) {
            //trow exception empty stack and quit app
        }
        _stack.push_back(result);
    }
    else {
        //trow exception empty stack and quit app
    }
}

void AbstractVM::sub()
{
    if (!_stack.empty() && _stack.size() >= 2){
        IOperand const * lhs = _stack.back();
        _stack.pop_back();
        IOperand const * rhs = _stack.back();
        _stack.pop_back();
        IOperand const * result = *lhs - *rhs;
        if (result == nullptr) {
            //trow exception empty stack and quit app
        }
        _stack.push_back(result);
    }
    else {
        //trow exception empty stack and quit app
    }
}

void AbstractVM::mult()
{
    if (!_stack.empty() && _stack.size() >= 2){
        IOperand const * lhs = _stack.back();
        _stack.pop_back();
        IOperand const * rhs = _stack.back();
        _stack.pop_back();
        IOperand const * result = *lhs * *rhs;
        if (result == nullptr) {
            //trow exception empty stack and quit app
        }
        _stack.push_back(result);
    }
    else {
        //trow exception empty stack and quit app
    }
    
}

void AbstractVM::div()
{
    if (!_stack.empty() && _stack.size() >= 2){
        IOperand const * lhs = _stack.back();
        _stack.pop_back();
        IOperand const * rhs = _stack.back();
        _stack.pop_back();
        IOperand const * result = *lhs / *rhs;
        if (result == nullptr) {
            //trow exception empty stack and quit app
        }
        _stack.push_back(result);
    }
    else {
        //trow exception empty stack and quit app
    }
    
}

void AbstractVM::mod()
{
    if (!_stack.empty() && _stack.size() >= 2){
        IOperand const * lhs = _stack.back();
        _stack.pop_back();
        IOperand const * rhs = _stack.back();
        _stack.pop_back();
        IOperand const * result = *lhs % *rhs;
        if (result == nullptr) {
            //trow exception empty stack and quit app
        }
        _stack.push_back(result);
    }
    else {
        //trow exception empty stack and quit app
    }

}

void AbstractVM::print() const
{
    
}

void AbstractVM::exit()
{
    
}
