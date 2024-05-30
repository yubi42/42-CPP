#pragma once

#include <iostream>
#include <string>
#include <stdexcept>

class AForm;

class Intern
{
private:
    std::pair<std::string, AForm *(Intern::*)(std::string)> form[3];
    AForm *CreateShrubberyForm(std::string target);
    AForm *CreateRobotomyForm(std::string target);
    AForm *CreatePresidentialForm(std::string target);

public:
    Intern();
    Intern(const Intern& src);
    Intern& operator=(const Intern& src);
    virtual ~Intern();

    AForm *makeForm(std::string form_name, std::string form_target);
};

