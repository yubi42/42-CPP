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
    if(_inputstream.fail() || ch > '9' || ch < '0')
        throw std::invalid_argument("Error: First value");
    _value = ch - '0';
    while(_inputstream >> ch)
    {
        if(std::isdigit(ch))
            _stack.push(ch - '0');
        else 
        {
            if(_stack.empty())
                throw std::invalid_argument("Error: Missing operand for operation");
            switch (ch)
            {
                case '+' :
                    _value += _stack.top();
                    break ;
                case '-' :
                    _value -= _stack.top();
                    break ;
                case '*' :
                    _value *= _stack.top();
                    break ;
                case '/' :
                    if(_stack.top() == 0) 
                        throw std::invalid_argument("Error: / 0"); 
                    _value /= _stack.top();
                    break ;
                default :
                    throw std::invalid_argument("Error: Other operator than '+-*/'");
            }
             _stack.pop();
        }
    }
    if(!_stack.empty())
        throw std::invalid_argument("Error: Stack not empty");
}

int RPN::getValue() const
{
    return (_value);
}