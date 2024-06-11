#pragma once

#include <iostream>
#include <string>
#include <stdexcept>

class Bureaucrat;

class Form
{
private:
    const std::string _name;
    bool _signed;
    const int _signMin;
    const int _execMin;

    void testGrade(int grade) const;

public:
    Form();
    Form(std::string name, int signGrade, int execGrade);
    Form(const Form& src);
    Form& operator=(const Form& src);
    virtual ~Form();

    std::string getName() const;
    bool getSignedStatus() const;
    int getSignMin() const;
    int getExecMin() const;

    void beSigned(const Bureaucrat& bureaucrat);
    
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

std::ostream& operator<<(std::ostream& os, const Form& src);
