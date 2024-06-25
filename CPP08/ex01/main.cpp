#include "Span.hpp"

int main()
{
    try
    {
    Span s1(10000);

    for(int i = 0; i < 10000; ++i)
    {
        s1.addNumber(i * (i + 3));
    }
    std::cout << std::endl;

    std::cout << "Shortest Span is: " << s1.shortestSpan() << std::endl;
    std::cout << "Longest Span is: " << s1.longestSpan() << std::endl;

    Span s2(10000);
    std::vector<int> vec;
    for(int i = 0; i < 10000; ++i)
    {
        vec.push_back(i * (i + 3));
    }
    s2.rangeOfIterators(vec.begin(), vec.end());
    std::cout << "Shortest Span is: " << s2.shortestSpan() << std::endl;
    std::cout << "Longest Span is: " << s2.longestSpan() << std::endl;

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}