#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShubberyCreationForm", 145, 137), _target("default")
{
std::cout << "target is: " << _target << "." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShubberyCreationForm", 145, 137), _target(target)
{
std::cout << "target is: " << _target << "." << std::endl;
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
    AForm::execute(executor);
    std::ofstream ofstream((_target + "_shrubbery").c_str());
    if(ofstream.fail())
    {
        std::cerr << "Failed to create file" << std::endl;
        return;
    }
    ofstream << "          .     .  .      +     .      .          .\n";
    ofstream << "     .       .      .     #       .           .\n";
    ofstream << "        .      .         ###            .      .      .\n";
    ofstream << "      .      .   \"#:. .:##\"##:. .:#\"  .      .\n";
    ofstream << "          .      . \"####\"###\"####\"  .\n";
    ofstream << "       .     \"#:.    .:#\"###\"#:.    .:#\"  .        .       .\n";
    ofstream << "  .             \"#########\"#########\"        .        .\n";
    ofstream << "        .    \"#:.  \"####\"###\"####\"  .:#\"   .       .\n";
    ofstream << "     .     .  \"#######\"\"##\"##\"\"#######\"                  .\n";
    ofstream << "                .\"##\"#####\"#####\"##\"           .      .\n";
    ofstream << "    .   \"#:. ...  .:##\"###\"###\"##:.  ... .:#\"     .\n";
    ofstream << "      .     \"#######\"##\"#####\"##\"#######\"      .     .\n";
    ofstream << "    .    .     \"#####\"\"#######\"\"#####\"    .      .\n";
    ofstream << "            .     \"      000      \"    .     .\n";
    ofstream << "       .         .   .   000     .        .       .\n";
    ofstream << ".. .. ..................O000O........................ ...... ...\n";
    ofstream.close();
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
std::cout << "ShrubberyCreationForm is not needed any longer." << std::endl;
}