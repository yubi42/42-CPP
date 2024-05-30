#pragma once

#include <iostream>
#include <string>
#include <stdexcept>

class AForm;

class Bureaucrat
{
private:
    const std::string _name;
    int _grade;
    void testGrade(int grade) const;

public:
    Bureaucrat();
    Bureaucrat(std::string name, int grade);
    Bureaucrat(const Bureaucrat& src);
    Bureaucrat& operator=(const Bureaucrat& src);
    virtual ~Bureaucrat();


    std::string getName() const;
    int getGrade() const;
    void upGrade();
    void downGrade();
    void signForm(AForm &AForm);
    void executeForm(AForm &AForm);

    class GradeTooHighException : public std::exception
    {
    public:
        virtual const char* what() const throw();
    };
    
    class GradeTooLowException : public std::exception
    {
    public:
        virtual const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream &os, const Bureaucrat& src);
    