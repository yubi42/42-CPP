#include <RPN.hpp>

RPN::RPN(std::string input) : _inputstream(input)
{
    _inputstream >> _value;
    if(_inputstream.fail() || _value >= 10 || _value < 0)
        throw std::invalid_argument("Error");
}

RPN::RPN(const RPN &src) : _inputstream(src._inputstream.str()), _queue(src._queue), _value(src._value)
{}

RPN &RPN::operator=(const RPN &src)
{
    if (this == &src)
        return (*this);

    _inputstream.str(src._inputstream.str());
    _inputstream.clear();
    _queue = src._queue;
    _value = src._value;
    return (*this);
}

RPN::~RPN(){}

void RPN::calculate()
{
    char ch;
    _inputstream >> std::noskipws;
    _inputstream >> ch;
    while(_inputstream >> ch)
    {
        if(std::isdigit(ch))
            _queue.push(ch - '0');
        else 
        {
            if(_queue.empty())
                throw std::invalid_argument("Error");
            switch (ch)
            {
                case '+' :
                    _value += _queue.front();
                    break ;
                case '-' :
                    _value -= _queue.front();
                    break ;
                case '*' :
                    _value *= _queue.front();
                    break ;
                case '/' :
                    if(_queue.front() == 0) 
                        throw std::invalid_argument("Error"); 
                    _value /= _queue.front();
                    break ;
                default :
                    throw std::invalid_argument("Error");
            }
             _queue.pop();
        }
        if(_inputstream.peek() == ' ')
        {
            std::cout << _inputstream.peek() << std::endl;
            if (_inputstream.peek() == -1)
                throw std::invalid_argument("Error");
        }
    }
    if(!_queue.empty())
        throw std::invalid_argument("Error");
}

int RPN::getValue() const
{
    return (_value);
}