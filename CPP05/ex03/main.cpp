#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"

int main ()
{
Intern someRandomIntern;
Intern secondIntern(someRandomIntern);
AForm *form;

form = secondIntern.makeForm("robotomy request", "Bender");
std::cout << *form << std::endl;
delete form;
std::cout << std::endl;

form = secondIntern.makeForm("shrubbery creation", "shubby");
std::cout << *form << std::endl;
delete form;
std::cout << std::endl;
}