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
struct TypeName<std::vector<std::pair<int, int> > > 
{
    static std::string name() { return ("std::vector<int>"); }
};

template<>
struct TypeName<std::deque<int> > 
{
    static std::string name() { return ("std::deque<int>"); }
};

template<>
struct TypeName<std::deque<std::pair<int, int> > >
{
    static std::string name() { return ("std::deque<int>"); }
};

template<>
struct TypeName<std::list<int> > 
{
    static std::string name() { return ("std::list<int>"); }
};

template<>
struct TypeName<std::list<std::pair<int, int> > >
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
            int value;
            sstream >> value;
            if(sstream.fail() || !sstream.eof() || value <= 0)
                throw std::invalid_argument("Error: Not an positive integer");
            arr.push_back(value);
        }
    }

    template<typename T>
    void parseInputPairs(size_t ac, char **av, T &arr) 
    {
        for(size_t i = 1; i < ac; ++i)
        {
            std::istringstream sstream(av[i]);
            int value;
            sstream >> value;
            if(sstream.fail() || !sstream.eof() || value <= 0)
                throw std::invalid_argument("Error: Not an integer");
            arr.push_back(std::make_pair(-1, value));
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

    template<typename T>
    void displayArrPairs(std::string message, const T &arr)
    {
        std::cout << message << ' ';
        typename T::const_iterator end = arr.end();
        for(typename T::const_iterator it = arr.begin(); it != end; ++it)
        {
            std::cout << it->second << ' ';
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
    void johnsonSort(T &start_array)
    { 
        T sorted_array;
        if (start_array.size() == 1)
            return ;
        else if (start_array.size() == 2)
        {
            typename T::iterator it = start_array.begin();
            typename T::iterator next = start_array.begin();
            ++next;
            if(*it > *next)
                std::swap(*it, *next);
            return ;
        }
        johnsonAlgorithm(start_array, sorted_array);
        start_array = sorted_array;
    }

    void johnsonInsertPairs(const std::list<std::pair<int, int> > &split_array, std::list<std::pair<int, int> > &sorted_array);

    template<typename T>
    void johnsonInsertPairs(const T &split_array, T &sorted_array)
    {
        size_t split_len = split_array.size();
        size_t end_len = sorted_array.size() + split_len;
        size_t j;
        for(size_t i = 0; i < end_len; ++i)
        {
            j = 0;
            while(split_array[j].second != sorted_array[i].second)
                ++j;
            if(split_array[j].first == -1)
            {
                --end_len;
                continue ;
            }
            size_t low = 0;
            size_t high = i;
            size_t mid;
            while (low != high)
            {
                mid = low + ((high - low) / 2);
                if (split_array[j].first < sorted_array[mid].second)
                    high = mid;
                else 
                    low = ++mid;
            }
            sorted_array.insert(sorted_array.begin() + low, std::make_pair(-1, split_array[j].first));
            ++i;
        }      
    }

    template<typename T>
    void johnsonMergePairs(const T &array, T &split_array)
    {
        for(typename T::const_iterator it = array.begin(); it != array.end(); ++it)
        {
            int value1 = it->second;
            ++it;
            if(it == array.end())
            {
                split_array.push_back(std::make_pair(-1, value1));
                break ;
            }
            int value2 = it->second;
            if(value1 < value2)
                split_array.push_back(std::make_pair(value1, value2));
            else
                split_array.push_back(std::make_pair(value2, value1));
            
        }
    }

    template<typename T>
    void johnsonAlgorithmPairs(const T &array, T &sorted_array)
    {
        T split_array;
        johnsonMergePairs(array, split_array);
        size_t split_array_size = split_array.size();
        if(split_array_size > 2)
            johnsonAlgorithmPairs(split_array, sorted_array);
        else
        {
            typename T::iterator it = split_array.begin();
            int value1 = it->second;
            ++it;
            if(value1 < it->second)
            {
                sorted_array.push_back(std::make_pair(-1, value1));
                sorted_array.push_back(std::make_pair(-1, it->second));
            }
            else
            {
                sorted_array.push_back(std::make_pair(-1, it->second));         
                sorted_array.push_back(std::make_pair(-1, value1));
            }
        }
        johnsonInsertPairs(split_array, sorted_array);
    }

    template<typename T>
    void johnsonSortPairs(T &array)
    {
        if (array.size() == 1)
            return ;
        else if (array.size() == 2)
        {
            typename T::iterator it = array.begin();
            typename T::iterator next = array.begin();
            ++next;
            if(it->second > next->second)
                std::swap(*it, *next);
            return ;
        }
        T sorted_array;

        johnsonAlgorithmPairs(array, sorted_array);
        array = sorted_array;
    }
};