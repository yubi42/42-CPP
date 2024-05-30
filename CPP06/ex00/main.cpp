#include "ScalarConverter.hpp"
#include "Utils.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Error" << std::endl << "Usage: ./a.out <input>" << std::endl;
        return (1);
    }
    ScalarConverter::convert(av[1]);
    return (0);
}