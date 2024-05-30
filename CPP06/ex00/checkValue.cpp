#include "Utils.hpp"

bool hasF(const std::string &input)
{
    return(input.find('f') != std::string::npos);
}

bool hasDot(const std::string &input)
{
    return(input.find('.') != std::string::npos);
}

bool isSpecial(const std::string &input)
{
    return(input == "nan" || input == "nanf" || input == "+inf" || input == "+inff" || input == "-inf" || input == "-inff");
}

bool isChar(const std::string &input)
{
    return(input.length() == 1 && isprint(input[0]));
}

bool isInt(const std::string &input, int &output)
{
    std::istringstream iss(input);
    iss >> output;
    return !(iss.fail() || !iss.eof());
}

bool isFloat(std::string input, float &output)
{
    if(!(hasF(input) && hasDot(input)))
        return false;

    input.erase(input.size() - 1);
    std::istringstream iss(input);
    iss >> output;
    return !(iss.fail() || !iss.eof());
}

bool isDouble(const std::string &input, double &output)
{
    std::istringstream iss(input);
    iss >> output;
    return !(iss.fail() || !iss.eof());
}
