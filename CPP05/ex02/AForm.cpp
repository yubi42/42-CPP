#include "AForm.hpp"
#include "Bureaucrat.hpp"

// orthodox canonical AForm

AForm::AForm() : _name("Default"), _signed(false), _signMin(1), _execMin(1)
{
    std::cout << "AForm: \"" << _name << "\" got created." << std::endl;
}

AForm::AForm(std::string name, int signMin, int execMin) : _name(name), _signed(false), _signMin(signMin), _execMin(execMin)
{
    std::cout << "AForm: \"" << _name << "\" got created." << std::endl;
}

AForm::AForm(const AForm& src) : _name(src._name), _signed(src._signed), _signMin(src._signMin), _execMin(src._execMin)
{
    std::cout << "AForm: \"" << _name << "\" got duplicated." << std::endl;
}

AForm& AForm::operator=(const AForm& src)
{
    (void)src;
    std::cout << "Can not assign two AForms." << std::endl;
    return (*this);
}

AForm::~AForm()
{
    std::cout << "AForm: \"" << _name << "\" got shredded." << std::endl;
}

// public 

std::string AForm::getName(void) const
{
	return _name;
}

bool AForm::getSignedStatus(void) const
{
	return _signed;
}

int AForm::getSignMin(void) const
{
	return _signMin;
}

int AForm::getExecMin(void) const
{
	return _execMin;
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > _signMin)
        throw AForm::GradeTooLowException();
    _signed = true;
}

void AForm::execute(const Bureaucrat& executor) const
{
    if(executor.getGrade() > (*this).getExecMin())
        throw AForm::GradeTooLowException();
    if(!(*this).getSignedStatus())
        throw AForm::FormNotSignedException();
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Grade too high.";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Grade too low.";
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return "Form not signed.";
}

std::ostream& operator<<(std::ostream &os, const AForm& src)
{
    os << ">>AForm \"" << src.getName() << "\" | signed: " << src.getSignedStatus() << " | sign grade >= " << src.getSignMin() << " | exec grade >= " << src.getExecMin() << "<<";
	return os;
}
