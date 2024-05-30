#include "Utils.hpp"

void printValue(const std::string &input)
{
    std::string part;
    if(input[0] == 'n')
        part = "nan";
    else if(input[0] == '+')
        part = "+inf";
    else 
        part = "-inf";
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: " << part << "f" << std::endl;
    std::cout << "double: " << part << std::endl;
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
    if (value >= 0 && value <= 127)
    {
        char c = static_cast<char>(value);
        std::cout << "char: " << (isprint(c) ? ("'" + std::string(1, c) + "'") : "Not printable") << std::endl;
    }
    else 
        std::cout << "char: impossible" << std::endl;
    std::cout << "int: " << value << std::endl;
    if (value >= -std::numeric_limits<float>::max() && value <= std::numeric_limits<float>::max())
        std::cout << "float: " << static_cast<float>(value) << ".0" << "f" << std::endl;
    else
        std::cout << "float: impossible" << std::endl;
    if (value >= -std::numeric_limits<double>::max() && value <= std::numeric_limits<double>::max())
        std::cout << "double: " << static_cast<double>(value) << ".0" << std::endl;
    else
        std::cout << "double: impossible" << std::endl;
}

void printValue(const float &value)
{
    bool need_dot = (value == (int)value);
    if (value >= 0 && value <= 127)
    {
        char c = static_cast<char>(value);
        std::cout << "char: " << (isprint(c) ? ("'" + std::string(1, c) + "'") : "Not printable") << std::endl;
    }
    else 
        std::cout << "char: impossible" << std::endl;
    if (value >= -std::numeric_limits<int>::max() && value <= std::numeric_limits<int>::max())
        std::cout << "int: " << static_cast<int>(value) << std::endl;
    else
        std::cout << "int: impossible" << std::endl;
    std::cout << "float: " << value << (need_dot ? ".0" : "") << "f" << std::endl;
    if (value >= -std::numeric_limits<double>::max() && value <= std::numeric_limits<double>::max())
        std::cout << "double: " << static_cast<double>(value) << (need_dot ? ".0" : "") << std::endl;
    else
        std::cout << "double: impossible" << std::endl;
}

void printValue(const double &value)
{
    bool need_dot = (value == (int)value);
    if (value >= 0 && value <= 127)
    {
        char c = static_cast<char>(value);
        std::cout << "char: " << (isprint(c) ? ("'" + std::string(1, c) + "'") : "Not printable") << std::endl;
    }
    else 
        std::cout << "char: impossible" << std::endl;
    if (value >= -std::numeric_limits<int>::max() && value <= std::numeric_limits<int>::max())
        std::cout << "int: " << static_cast<int>(value) << std::endl;
    else
        std::cout << "int: impossible" << std::endl;
    if (value >= -std::numeric_limits<float>::max() && value <= std::numeric_limits<float>::max())
        std::cout << "float: " << static_cast<float>(value) << (need_dot ? ".0" : "") << "f" << std::endl;
    else
        std::cout << "float: impossible" << std::endl;
    std::cout << "double: " << value << (need_dot ? ".0" : "") << std::endl;
}
