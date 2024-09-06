#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <iterator>
#include <algorithm>

#define RED "\033[0;31m"
#define COL_RESET "\033[0m"

class Span
{
private:
    unsigned int _N;
    std::vector<int> _vec;
    
    Span();
    std::string redError(std::string msg);

public:
    Span(const unsigned int N);
    Span(const Span& other);
    Span& operator=(const Span& other);    
    virtual ~Span();

    void addNumber(int num);
    void addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);
    int shortestSpan();
    int longestSpan();

};