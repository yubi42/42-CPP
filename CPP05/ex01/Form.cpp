#include "Form.hpp"
#include "Bureaucrat.hpp"

// orthodox canonical form

Form::Form() : _name("Default"), _signed(false), _signMin(1), _execMin(1)
{
    std::cout << "Form: \"" << _name << "\" got created." << std::endl;
}

Form::Form(std::string name, int signMin, int execMin) : _name(name), _signed(false), _signMin(signMin), _execMin(execMin)
{
    std::cout << "Form: \"" << _name << "\" got created." << std::endl;
}

Form::Form(const Form& src) : _name(src._name), _signed(src._signed), _signMin(src._signMin), _execMin(src._execMin)
{
    std::cout << "Form: \"" << _name << "\" got duplicated." << std::endl;
}

Form& Form::operator=(const Form& src)
{
    (void)src;
    std::cout << "Can not assign two forms." << std::endl;
    return (*this);
}

Form::~Form()
{
    std::cout << "Form: \"" << _name << "\" got shredded." << std::endl;
}

// public 

std::string Form::getName(void) const
{
	return _name;
}

bool Form::getSignedStatus(void) const
{
	return _signed;
}

int Form::getSignMin(void) const
{
	return _signMin;
}

int Form::getExecMin(void) const
{
	return _execMin;
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > _signMin)
        throw Form::GradeTooLowException();
    _signed = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Grade too high.";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Grade too low.";
}

std::ostream& operator<<(std::ostream &os, const Form& src)
{
    os << ">>Form \"" << src.getName() << "\" | signed: " << src.getSignedStatus() << " | sign grade >= " << src.getSignMin() << " | exec grade >= " << src.getExecMin() << "<<";
	return os;
}
