#include "Span.hpp"

// orthodox canonical form

Span::Span() : _N(0) {}

Span::Span(const unsigned int N) : _N(N) {}

Span::Span(const Span &src) : _N(src._N), _vec(src._vec) {}

Span& Span::operator=(const Span& src) 
{
    if(this == &src)
        return (*this);
    _N = src._N;
    _vec = src._vec;
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
    size_t size = _vec.size();
    if (size < 2)
        throw std::length_error(redError("\nError: Span must at least contain 2 elements"));
    
    std::vector<int> vec_sorted(_vec);
    std::sort(vec_sorted.begin(), vec_sorted.end());

    int s_span = vec_sorted[1] - vec_sorted[0];
    for(size_t i = 1; i < size - 1; ++i)
    {
        int tmp = vec_sorted[i + 1] - vec_sorted[i];
        s_span = std::min(s_span, tmp);
    }
    return (s_span);
}

int Span::longestSpan()
{
    size_t size = _vec.size();
    if (size < 2)
        throw std::length_error(redError("\nError: Span must at least contain 2 elements"));

    std::vector<int> vec_sorted(_vec);
    std::sort(vec_sorted.begin(), vec_sorted.end());
    return(vec_sorted.back() - vec_sorted.front());
}

void Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    size_t dis = std::distance(begin, end);
    if(_vec.size() + dis > _N)
        throw std::length_error(redError("Error: Too many elements"));
    _vec.insert(_vec.end(), begin, end);
}
