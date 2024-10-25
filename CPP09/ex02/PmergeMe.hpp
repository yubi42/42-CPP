#pragma once

#include <string>
#include <sstream>
#include <iostream>
#include <ctime>
#include <exception>
#include <vector>
#include <deque>
#include <algorithm>
#include <typeinfo>
#include <iomanip>
#include <list>
#include <queue>

template<typename T>
struct TypeName 
{
    static std::string name() { return ("Unknown type"); }
};

template<>
struct TypeName<std::vector<int> > 
{
    static std::string name() { return ("std::vector<int>"); }
};

template<>
struct TypeName<std::deque<int> > 
{
    static std::string name() { return ("std::deque<int>"); }
};

template<>
struct TypeName<std::list<int> > 
{
    static std::string name() { return ("std::list<int>"); }
};

class PmergeMe
{
private:
    PmergeMe(const PmergeMe &src);
    PmergeMe& operator=(const PmergeMe &src);
public:
    PmergeMe();
    virtual ~PmergeMe();

    template<typename T>
    void parseInput(size_t ac, char **av, T &arr) 
    {
        for(size_t i = 1; i < ac; ++i)
        {
            std::istringstream sstream(av[i]);
            unsigned int value;
            sstream >> value;
            if(sstream.fail() || !sstream.eof())
                throw std::invalid_argument("Error: Not an integer");
            arr.push_back(value);
        }
    }

    template<typename T>
    std::string getType(const T&) { return TypeName<T>::name(); }

    template<typename T>
    void displayResults(std::pair<clock_t, clock_t> time, const T &arr)
    {
        double duration = static_cast<double>(time.second - time.first) / CLOCKS_PER_SEC * 1e6;
        std::cout << "Time to process a range of " << arr.size() << " elements with " << getType(arr) << " : " << duration << " us" << std::endl;
    }

    template<typename T>
    void displayArr(std::string message, const T &arr)
    {
        std::cout << message << ' ';
        typename T::const_iterator end = arr.end();
        for(typename T::const_iterator it = arr.begin(); it != end; ++it)
        {
            std::cout << *it << ' ';
        }
        std::cout << std::endl;
    }

    void johnsonMerge(std::list<int> &small_values, std::list<int> &big_values);

    template<typename T>
    void johnsonMerge(T &small_values, T &big_values)
    {
        size_t small_size = small_values.size();
        size_t len = small_size / 2;
        for(size_t i = 0; i < len; ++i)
        {
            if (small_values[i] > small_values[i + 1]) 
            {
                big_values.push_back(small_values[i]);
                small_values.erase(small_values.begin() + i);
            } 
            else 
            {
                big_values.push_back(small_values[i + 1]);
                small_values.erase(small_values.begin() + i + 1);
            }
        }
        if (small_size % 2)
        {
            big_values.push_back(small_values[len]);
            small_values.erase(small_values.end() - 1);
        }
        // displayArr("small array:", small_values);
        // displayArr("big array:", big_values);
    }

    void johnsonInsert(std::list<int> &small_values, std::list<int> &big_values, std::list<int> &sorted_array);

    template<typename T>
    void johnsonInsert(T &small_values, T &big_values, T &sorted_array)
    {
        if(small_values.size() < big_values.size())
            big_values.pop_back();
    
        size_t end_len = sorted_array.size() + small_values.size();
        size_t big_len = big_values.size();
        size_t j;
        for(size_t i = 0; i < end_len; ++i)
        {
            j = 0;
            while(j < big_len && sorted_array[i] != big_values[j])
                ++j;
            if(j != big_len)
            {
                size_t low = 0;
                size_t high = i;
                size_t mid;
                while (low != high)
                {
                    mid = low + ((high - low) / 2);
                    if (small_values[j] < sorted_array[mid])
                        high = mid;
                    else 
                        low = ++mid;
                }
                sorted_array.insert(sorted_array.begin() + low, small_values[j]);
                ++i;
            }
        }
    }
    
    template<typename T>
    void johnsonAlgorithm(T small_values, T &sorted_array)
    {
        T big_values;
        johnsonMerge(small_values, big_values);
        size_t big_values_size = big_values.size();
        if(big_values_size > 2)
            johnsonAlgorithm(big_values, sorted_array);
        else if(big_values_size == 2) 
        {
            typename T::iterator big_it = big_values.begin();
            typename T::iterator big_next = big_values.begin();
            ++big_next;

            if(*big_it < *big_next)
            {
                sorted_array.push_back(*big_it);
                sorted_array.push_back(*big_next);
            }
            else
            {
                sorted_array.push_back(*big_next);
                sorted_array.push_back(*big_it);
            }
        }
        johnsonInsert(small_values, big_values, sorted_array);
    }

    template<typename T>
    void johnsonSort(T &start_arr)
    { 
        T sorted_array;
    
        johnsonAlgorithm(start_arr, sorted_array);
        start_arr = sorted_array;
    }

};