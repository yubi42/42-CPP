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
}