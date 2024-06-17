#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default")
{
std::cout << "target is: " << _target << "." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
std::cout << "target is: " << _target << "." << std::endl;
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
    AForm::execute(executor);
    std::srand(std::time(NULL));
    if(std::rand() % 2)
        std::cout << _target << " has been robotomized successfully!" << std::endl;
    else
        std::cout << _target << " could not be robotomized - robotomy failed." << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
std::cout << "RobotomyRequestForm is not needed any longer." << std::endl;
}