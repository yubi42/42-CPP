#include <RPN.hpp>

int main(int ac, char **av)
{
    if (ac != 2)
        return (1);
    
    try
    {
        RPN rpn(av[1]);
        rpn.calculate();
        std::cout << rpn.getValue() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
        return (1);
    }

    return (0);
}