#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 72, 75), _target("default")
{
std::cout << "target is: " << _target << "." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 72, 75), _target(target)
{
std::cout << "target is: " << _target << "." << std::endl;
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
    AForm::execute(executor);
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
std::cout << "PresidentialPardonForm is not needed any longer." << std::endl;
}