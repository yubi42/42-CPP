#include <iostream>
#include <string>

int main() {
    std::string str = "HI THIS IS BRAIN";
    std::string* strPTR = &str;
    std::string& strREF = str;

    std::cout << "Memory address of the string variable: " << &str << std::endl;
    std::cout << "Memory address held by strPTR: " << strPTR << std::endl;
    std::cout << "Memory address held by strREF: " << &strREF << std::endl;

    std::cout << "Value of the string variable: " << str << std::endl;
    std::cout << "Value pointed to by strPTR: " << *strPTR << std::endl;
    std::cout << "Value pointed to by strREF: " << strREF << std::endl;

    return 0;
}