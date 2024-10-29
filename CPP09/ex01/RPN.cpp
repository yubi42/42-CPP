#include <RPN.hpp>

RPN::RPN(){}

RPN::RPN(std::string input) : _inputstream(input) {}

RPN::RPN(const RPN &src) : _inputstream(src._inputstream.str()), _stack(src._stack), _value(src._value) {}

RPN &RPN::operator=(const RPN &src)
{
    if (this == &src)
        return (*this);

    _inputstream.str(src._inputstream.str());
    _stack = src._stack;
    _value = src._value;
    return (*this);
}

RPN::~RPN(){}

void RPN::calculate()
{
    char ch;
    _inputstream >> ch;
    if(std::isdigit(ch))
        _stack.push(ch - '0');
    else
        throw std::invalid_argument("Error: First value");
    while(_inputstream >> ch)
    {
        if(std::isdigit(ch))
            _stack.push(ch - '0');
        else 
        {
            if(_stack.size() < 2)
                throw std::invalid_argument("Error: Missing operand for operation");
            int value2 = _stack.top();
            _stack.pop();
            int value1 = _stack.top();
            _stack.pop();
            switch (ch)
            {
                case '+' :
                    value1 += value2;
                    break ;
                case '-' :
                    value1 -= value2;
                    break ;
                case '*' :
                    value1 *= value2;
                    break ;
                case '/' :
                    if(value2 == 0) 
                        throw std::invalid_argument("Error: / 0"); 
                    value1 /= value2;
                    break ;
                default :
                    throw std::invalid_argument("Error: Other operator than '+-*/'");
            }
            _stack.push(value1);
        }
    }
    if(_stack.size() > 1)
        throw std::invalid_argument("Error: Stack not empty");
    _value = _stack.top();
}

int RPN::getValue() const
{
    return (_value);
}