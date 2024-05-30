#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"

int main ()
{
Intern someRandomIntern;
Intern secondIntern(someRandomIntern);
AForm *rrf;

rrf = secondIntern.makeForm("robotomy request", "Bender");
std::cout << *rrf << std::endl;
delete rrf;

rrf = secondIntern.makeForm("shrubbery creation", "shubby");
std::cout << *rrf << std::endl;

delete rrf;
}