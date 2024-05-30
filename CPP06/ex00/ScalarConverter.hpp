#pragma once

#include <string>

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &src);
        ScalarConverter &operator=(const ScalarConverter &src);

    public:
        virtual ~ScalarConverter();
        static void convert(const std::string &input);
};

