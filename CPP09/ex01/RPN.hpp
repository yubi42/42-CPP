#pragma once

#include <iostream>
#include <string>
#include <stack>
#include <stdexcept>
#include <sstream>

class RPN
{
    private:
        std::stringstream _inputstream;
        std::stack<int> _stack;
        int _value;

        RPN();
    
    public:
        RPN(std::string input);
        RPN(const RPN &src);
        RPN &operator=(const RPN &src);
        virtual ~RPN();
    
        void calculate();
        int getValue() const;
};

