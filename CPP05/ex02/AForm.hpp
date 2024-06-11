#pragma once

#include <iostream>
#include <string>
#include <stdexcept>

class Bureaucrat;

class AForm
{
private:
    const std::string _name;
    bool _signed;
    const int _signMin;
    const int _execMin;

    void testGrade(int grade) const;

protected:
    AForm();
    AForm(std::string name, int signGrade, int execGrade);

public:
    AForm(const AForm& src);
    AForm& operator=(const AForm& src);
    virtual ~AForm();

    std::string getName() const;
    bool getSignedStatus() const;
    int getSignMin() const;
    int getExecMin() const;

    void beSigned(const Bureaucrat& bureaucrat);
    virtual void execute(const Bureaucrat& executor) const;
    
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

    class FormNotSignedException : public std::exception
    {
    public:
        virtual const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& os, const AForm& src);
