#include "easyfind.hpp"

int main()
{
    std::vector<int> vec;
    vec.push_back(0);
    for(size_t i = 0; i < 10; ++i)
    {
        if (i % 2)
            vec.push_back(i);
    }
    std::cout << "vector contains:" << std::endl;
    for(size_t i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i] << std::endl;
    }
    std::cout << std::endl;

    int num = 3;
    std::vector<int>::iterator it = easyfind(vec, num);
    std::cout << "Is " << num << " part of vector?" <<  std::endl;
    if (it != vec.end())
        std::cout << *it << " found" << std::endl;
    else 
        std::cout << num << " not found" << std::endl;
    std::cout << std::endl;

    num = 2;
    it = easyfind(vec, num);
    std::cout << "Is " << num << " part of vector?" <<  std::endl;
    if (it != vec.end())
        std::cout << *it << " found" << std::endl;
    else 
        std::cout << num << " not found" << std::endl;
}