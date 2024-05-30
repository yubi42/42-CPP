#include "AForm.hpp"

#include <fstream>

class ShrubberyCreationForm : public AForm
{
private:
    std::string _target;

public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(std::string target);
    ~ShrubberyCreationForm();

    void execute(const Bureaucrat& executor) const;
};
