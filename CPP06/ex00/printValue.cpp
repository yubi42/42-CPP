#include "Utils.hpp"

void printValue(const std::string &input)
{
    float f = 0;
    double d = 0;
    if(input[0] == 'n' && input.length() == 3)
        d = NAN;
    else if(input[0] == 'n')
        f = NAN;
    else if(input[0] == '+' && input.length() == 4)
        d = INFINITY;
    else if(input[0] == '+')
        f = INFINITY;
    else if(input[0] == '-' && input.length() == 4)
        d = -INFINITY;
    else if(input[0] == '-')
        f = -INFINITY;
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: " << (f ? f : static_cast<float>(d)) << "f" << std::endl;
    std::cout << "double: " << (d ? d : static_cast<double>(f)) << std::endl;
}

void printValue(const char &value)
{
    std::cout << "char: " << (isprint(value) ? ("'" + std::string(1, value) + "'") : "Not printable") << std::endl;
    std::cout << "int: " << static_cast<int>(value) << std::endl;
    std::cout << "float: " << static_cast<float>(value) << ".0" << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(value) << ".0" << std::endl;
}

void printValue(const int &value)
{
    if (value >= std::numeric_limits<char>::min() && value <= std::numeric_limits<char>::max())
    {
        char c = static_cast<char>(value);
        std::cout << "char: " << (isprint(c) ? ("'" + std::string(1, c) + "'") : "Not printable") << std::endl;
    }
    else 
        std::cout << "char: impossible" << std::endl;
    std::cout << "int: " << value << std::endl;
    std::cout << "float: " << static_cast<float>(value) << ".0" << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(value) << ".0" << std::endl;
}

void printValue(const float &value)
{
    bool need_dot = (value == static_cast<int>(value));
    if (value >= std::numeric_limits<char>::min() && value <= std::numeric_limits<char>::max())
    {
        char c = static_cast<char>(value);
        std::cout << "char: " << (isprint(c) ? ("'" + std::string(1, c) + "'") : "Not printable") << std::endl;
    }
    else 
        std::cout << "char: impossible" << std::endl;
    if (value >= std::numeric_limits<int>::min() && value <= std::numeric_limits<int>::max())
        std::cout << "int: " << static_cast<int>(value) << std::endl;
    else
        std::cout << "int: impossible" << std::endl;
    std::cout << "float: " << value << (need_dot ? ".0" : "") << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(value) << (need_dot ? ".0" : "") << std::endl;
}

void printValue(const double &value)
{
    bool need_dot = (value == static_cast<int>(value));
    if (value >= std::numeric_limits<char>::min() && value <= std::numeric_limits<char>::max())
    {
        char c = static_cast<char>(value);
        std::cout << "char: " << (isprint(c) ? ("'" + std::string(1, c) + "'") : "Not printable") << std::endl;
    }
    else 
        std::cout << "char: impossible" << std::endl;
    if (value >= std::numeric_limits<int>::min() && value <= std::numeric_limits<int>::max())
        std::cout << "int: " << static_cast<int>(value) << std::endl;
    else
        std::cout << "int: impossible" << std::endl;
    if (value >= std::numeric_limits<float>::min() && value <= std::numeric_limits<float>::max())
        std::cout << "float: " << static_cast<float>(value) << (need_dot ? ".0" : "") << "f" << std::endl;
    else
        std::cout << "float: impossible" << std::endl;
    std::cout << "double: " << value << (need_dot ? ".0" : "") << std::endl;
}
