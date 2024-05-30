#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
    form[0].first = "shrubbery creation";
    form[0].second = &Intern::CreateShrubberyForm;
    form[1].first = "robotomy request";
    form[1].second = &Intern::CreateRobotomyForm;
    form[2].first = "presidential pardon";
    form[2].second = &Intern::CreatePresidentialForm;

    std::cout << "Random Intern got hired." << std::endl;
}

Intern::Intern(const Intern& src)
{
    form[0] = src.form[0];
    form[1] = src.form[1];
    form[2] = src.form[2];

    std::cout << "Random Intern got cloned." << std::endl;
}

Intern& Intern::operator=(const Intern& src)
{
    form[0] = src.form[0];
    form[1] = src.form[1];
    form[2] = src.form[2];

    std::cout << "Random Intern got copy assigned." << std::endl;
    return (*this);
}

Intern::~Intern()
{
    std::cout << "Intern quit." << std::endl;
}

AForm *Intern::CreateShrubberyForm(std::string target)
{
    return (new ShrubberyCreationForm(target));
}

AForm *Intern::CreateRobotomyForm(std::string target)
{
    return (new RobotomyRequestForm(target));
}

AForm *Intern::CreatePresidentialForm(std::string target)
{
    return (new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(std::string form_name, std::string form_target)
{
    for(int i = 0; i < 3 ;++i)
    {
        if (form_name == form[i].first)
        {
            std::cout << "Intern creates \"" << form_name << "\"." << std::endl;
            return ((this->*form[i].second)(form_target));
        }
    }
    std::cerr << "Form name not found." << std::endl;
    return NULL;
}