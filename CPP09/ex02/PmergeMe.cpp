#include <PmergeMe.hpp>


// canonical orthodox form

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe &src) { (void)src; }
PmergeMe& PmergeMe::operator=(const PmergeMe &src) { (void)src; return *this;}
PmergeMe::~PmergeMe() {}

//

std::vector<size_t> PmergeMe::generateJacobsthalArray(size_t limit)
{
    std::vector<size_t> jacobsthal;
    jacobsthal.push_back(0);
    jacobsthal.push_back(1);
    while (true) 
    {
        size_t next_value = jacobsthal[jacobsthal.size() - 1] + 2 * jacobsthal[jacobsthal.size() - 2];
        if (next_value >= limit) break;
        jacobsthal.push_back(next_value);
    }
    return jacobsthal;
}
