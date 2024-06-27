#pragma once

#include <iostream>
#include <string>
#include <queue>
#include <stdexcept>
#include <sstream>

class RPN
{
    private:
        std::stringstream _inputstream;
        std::queue<int> _queue;
        int _value;
    
    public:
        RPN(std::string input);
        RPN(const RPN &src);
        RPN &operator=(const RPN &src);
        virtual ~RPN();
    
        void calculate();
        int getValue() const;
};

