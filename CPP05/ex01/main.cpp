#include "Bureaucrat.hpp"
#include "Form.hpp"

int main ()
{
    Bureaucrat boss("Boss", 1);
    Bureaucrat intern;
    Form form;
    intern.signForm(form);
    boss.signForm(form);
    std::cout << std::endl << form << std::endl << std::endl;
    try
    {
       Form form1("test", 151, 1);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Failed to create form: " << e.what() << std::endl;
    } 
    std::cout << std::endl;
}