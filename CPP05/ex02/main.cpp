#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main ()
{
Bureaucrat boss("Boss", 1);
Bureaucrat intern("Intern1", 150);
ShrubberyCreationForm shubby("shubby");
RobotomyRequestForm robby("Dog");
PresidentialPardonForm pressly("Intern1");
std::cout << std::endl;

std::cout << "***************** ShrubberyCreationForm *****************" << std::endl;

std::cout << std::endl;
boss.executeForm(shubby);
std::cout << std::endl;
boss.signForm(shubby);
std::cout << std::endl;
std::cout << shubby << std::endl;
std::cout << std::endl;
boss.executeForm(shubby);
std::cout << std::endl;

std::cout << "***************** RobotomyRequestForm *****************" << std::endl;

std::cout << std::endl;
intern.signForm(robby);
std::cout << std::endl;
intern.executeForm(robby);
std::cout << std::endl;
std::cout << robby << std::endl;
std::cout << std::endl;
boss.signForm(robby);
std::cout << std::endl;
boss.executeForm(robby);
std::cout << std::endl;

std::cout << "***************** PresidentialPardonForm *****************" << std::endl;

std::cout << std::endl;
intern.signForm(pressly);
std::cout << std::endl;
intern.executeForm(pressly);
std::cout << std::endl;
std::cout << pressly << std::endl;
std::cout << std::endl;
boss.signForm(pressly);
std::cout << std::endl;
boss.executeForm(pressly);
std::cout << std::endl;

}