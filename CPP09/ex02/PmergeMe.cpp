#include <PmergeMe.hpp>


// canonical orthodox form

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe &src) { (void)src; }
PmergeMe& PmergeMe::operator=(const PmergeMe &src) { (void)src; return *this;}
PmergeMe::~PmergeMe() {}

//

void PmergeMe::johnsonMerge(std::list<int> &small_values, std::list<int> &big_values)
{
    typename std::list<int>::iterator it = small_values.begin();
    typename std::list<int>::iterator small_end = small_values.end();
    while(it != small_end)
    {
            typename std::list<int>::iterator next_it = it;
            ++next_it;
            if (next_it != small_end) 
            {
                if (*it > *next_it) 
                {
                    big_values.push_back(*it);
                    it = small_values.erase(it);
                    ++it;
                } 
                else 
                {
                    big_values.push_back(*next_it);
                    it = small_values.erase(next_it);
                }
            }
            else
            {
                big_values.push_back(*it);
                small_values.erase(it);
                break;
            }
    }
}

void PmergeMe::johnsonInsert(std::list<int> &small_values, std::list<int> &big_values, std::list<int> &sorted_array)
{
    if(small_values.size() < big_values.size())
        big_values.pop_back();

    typename std::list<int>::iterator sorted_begin = sorted_array.begin();
    typename std::list<int>::iterator sorted_it = sorted_begin;
    typename std::list<int>::iterator sorted_end = sorted_array.end();
    typename std::list<int>::iterator big_begin = big_values.begin();
    typename std::list<int>::iterator big_end = big_values.end();
    typename std::list<int>::iterator small_begin = small_values.begin();
    typename std::list<int>::iterator big_it;
    typename std::list<int>::iterator small_it;
    int max_range = 0;
    while(sorted_it != sorted_end)
    {
        big_it = big_begin;
        small_it = small_begin;
        while(big_it != big_end && *big_it != *sorted_it)
        {
            ++big_it;
            ++small_it;
        }
        if (big_it != big_end)
        {
            typename std::list<int>::iterator low = sorted_begin;
            typename std::list<int>::iterator high = low;
            typename std::list<int>::iterator mid;
            std::advance(high, max_range);

            while (low != high)
            {
                mid = low;
                std::advance(mid, std::distance(low, high) / 2);
                if (*small_it < *mid)
                    high = mid;
                else
                    low = ++mid;
            }
            sorted_array.insert(low, *small_it);      
        }
        ++sorted_it;
        max_range += 2;
    }
}