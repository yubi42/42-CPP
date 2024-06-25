#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

/* int main ()
{
Intern someRandomIntern;
Intern secondIntern(someRandomIntern);
AForm *form;

form = secondIntern.makeForm("robotomy request", "Bender");
std::cout << *form << std::endl;
delete form;

form = secondIntern.makeForm("shrubbery creation", "shubby");
std::cout << *form << std::endl;

delete form;
}
 */

int main ()
{
Intern someRandomIntern;
Intern secondIntern(someRandomIntern);
AForm *form;
Bureaucrat bu("bu", 1);

form = secondIntern.makeForm("robotomy request", "Bender");
std::cout << *form << std::endl;
delete form;

form = secondIntern.makeForm("shrubbery creation", "shubby");
std::cout << *form << std::endl;
AForm *form2(form);
bu.signForm(*form2);
bu.executeForm(*form2);
bu.executeForm(*form);

delete form;
}
