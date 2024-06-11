#include "Bureaucrat.hpp"

int main ()
{
    Bureaucrat intern;
    Bureaucrat boss("Boss", 1);
    
    intern.downGrade();
    boss.upGrade();
    intern.upGrade();

    try
    {
        Bureaucrat sally("sally", 0);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Can not hire because: " << e.what() << std::endl;
    }
    std::cout << std::endl;
}
