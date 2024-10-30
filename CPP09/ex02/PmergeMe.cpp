#include <PmergeMe.hpp>


// canonical orthodox form

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe &src) { (void)src; }
PmergeMe& PmergeMe::operator=(const PmergeMe &src) { (void)src; return *this;}
PmergeMe::~PmergeMe() {}

//

std::vector<int> PmergeMe::generateJacobsthalArray(int limit)
{
    std::vector<int> jacobsthal;
    jacobsthal.push_back(0);
    jacobsthal.push_back(1);
    while (true) 
    {
        int next_value = jacobsthal[jacobsthal.size() - 1] + 2 * jacobsthal[jacobsthal.size() - 2];
        jacobsthal.push_back(next_value);
        if (next_value >= limit)
            break;
    }
    return jacobsthal;
}
