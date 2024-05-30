#include "ScalarConverter.hpp"
#include "Utils.hpp"

void ScalarConverter::convert(const std::string &input)
{
    int i;
    float f;
    double d;
    if(isSpecial(input))
        printValue(input);
    else if(isInt(input, i))
        printValue(i);
    else if(isChar(input))
        printValue(input[0]);
    else if(isFloat(input, f))
        printValue(f);
    else if(isDouble(input, d))
        printValue(d);
    else 
    {
        std::cerr << "Invalid input" << std::endl << "Usage: ./convert <char || int || float || double>" << std::endl;
        return ;
    }
}