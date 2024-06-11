#include "Bureaucrat.hpp"

// orthodox canonical form

Bureaucrat::Bureaucrat() : _name("Intern"), _grade(150)
{
    std::cout << "Default Bureaucrat " << _name << " got hired." << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
    std::cout << std::endl << "Trying to hire bureaucrat: " << _name << std::endl;
    testGrade(_grade);
    std::cout << "Bureaucrat " << _name << " got hired." << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade)
{
	std::cout << "Bureaucrat " << _name << " copy constructed." << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	_grade = other._grade;
	std::cout << "Bureaucrat " << _name << " copy assigned." << std::endl;
	return *this;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat " << _name << " quit." << std::endl;
}

// private

void Bureaucrat::testGrade(int grade) const
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

// public

std::string Bureaucrat::getName() const
{
    return _name;
}

int Bureaucrat::getGrade() const
{
    return _grade;
}

void Bureaucrat::upGrade()
{
    try
    {
        std::cout << std::endl << "Trying to promote " << *this << "." << std::endl;
        testGrade(_grade - 1);
        --_grade;
        std::cout << "Bureaucrat " << _name << " got promoted from: " << _grade + 1 << " to " << _grade << "." << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Can not promote because: " << e.what() << std::endl;
        return ;
    }
}

void Bureaucrat::downGrade()
{
    try
    {
        std::cout << std::endl << "Trying to demote " << *this << "." << std::endl;
        testGrade(_grade + 1);
        ++_grade;
        std::cout << "Bureaucrat " << _name << " got demoted from: " << _grade - 1 << " to " << _grade << "." << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Can not demote because: " << e.what() << std::endl;
        return ;
    }
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade too high.";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade too low.";
}

std::ostream& operator<<(std::ostream &os, Bureaucrat const& src)
{
    os << src.getName() << ", bureaucrat grade " << src.getGrade() << ".";
	return os;
}