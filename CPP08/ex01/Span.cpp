#include "Span.hpp"

// orthodox canonical form

Span::Span() : _N(0) {}

Span::Span(const unsigned int N) : _N(N) {}

Span::Span(const Span &other) : _N(other._N) {}

Span& Span::operator=(const Span& other) 
{
    (void)other;
    return (*this);
}

Span::~Span() {};

// private functions

std::string Span::redError(std::string msg)
{
    return(std::string(RED) + msg + std::string(COL_RESET));
}

// public functions

void Span::addNumber(int num)
{
    unsigned int size = _vec.size();
    if(size == _N)
        throw std::length_error(redError("Error: Span is full."));
    _vec.push_back(num);
    std::cout << "Addded: " << num << " at pos " << size << std::endl;
}

int Span::shortestSpan()
{
    unsigned int size = _vec.size();
    if (size < 2)
        throw std::length_error(redError("\nError: Span must at least contain 2 elements"));
    int s_span = _vec[0] + _vec[1];
    for(unsigned int i = 1; i < size - 1; ++i)
    {
        int tmp = abs(_vec[i] - _vec[i + 1]);
        if (tmp < s_span)
            s_span = tmp;
    }
    return (s_span);
}

int Span::longestSpan()
{
    unsigned int size = _vec.size();
    if (size < 2)
        throw std::length_error(redError("\nError: Span must at least contain 2 elements"));
    int l_span = _vec[0] + _vec[1];
    for(size_t i = 1; i < size - 1; ++i)
    {
        int tmp = abs(_vec[i] - _vec[i + 1]);
        if (tmp > l_span)
            l_span = tmp;
    }
    return (l_span);
}

void Span::rangeOfIterators(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    int dis = std::distance(begin, end);
    if(_vec.size() + dis > _N)
        throw std::length_error(redError("Error: Too many elements"));
    _vec.insert(_vec.end(), begin, end);
}
