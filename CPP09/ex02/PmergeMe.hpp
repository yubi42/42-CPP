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

public:
    PmergeMe();
    PmergeMe(const PmergeMe &src);
    PmergeMe& operator=(const PmergeMe &src);
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
    };

    template<typename T>
    void sortContainer(T &arr) { std::sort(arr.begin(), arr.end()); }
    
    template<typename T>
    void sortContainer(std::list<T> &arr) { arr.sort(); }

    template<typename T>
    void johnsonSort(T &arr)
    {
        T big_values_arr;
        typename T::iterator it = arr.begin();

        while (it != arr.end()) 
        {
            typename T::iterator next_it = it;
            ++next_it;
            if (next_it != arr.end()) 
            {
                if (*it > *next_it) 
                {
                    big_values_arr.push_back(*it);
                    it = arr.erase(it);
                } 
                else 
                {
                    big_values_arr.push_back(*next_it);
                    it = arr.erase(next_it);
                }
            }
            if(it != arr.end())
                ++it;
        }
        sortContainer(arr);
        for (typename T::iterator big_it = big_values_arr.begin(); big_it != big_values_arr.end(); ++big_it)
        {
            typename T::iterator insert_pos = std::upper_bound(arr.begin(), arr.end(), *big_it);
            arr.insert(insert_pos, *big_it);
        }
    };

    template<typename T>
    T johnsonSort2(const T &arr)
    {
        T big_values_arr;
        T small_values_arr;
        typename T::const_iterator end = arr.end();
        for(typename T::const_iterator it = arr.begin(); it != end; ++it) 
        {
            typename T::const_iterator next_it = it;
            ++next_it;
            if (next_it != end) 
            {
                if (*it > *next_it) 
                {
                    big_values_arr.push_back(*it);
                    small_values_arr.push_back(*next_it);
                } 
                else 
                {
                    big_values_arr.push_back(*next_it);
                    small_values_arr.push_back(*it);
                }
                ++it;
            }
            else
                small_values_arr.push_back(*it);
        }
        sortContainer(small_values_arr);
        for (typename T::iterator big_it = big_values_arr.begin(); big_it != big_values_arr.end(); ++big_it)
        {
            typename T::iterator insert_pos = std::upper_bound(small_values_arr.begin(), small_values_arr.end(), *big_it);
            small_values_arr.insert(insert_pos, *big_it);
        }
        return(small_values_arr);
    };

    template<typename T>
    T johnsonSort3(const T &arr)
    {
        T big_values_arr;
        T small_values_arr;
        size_t len = arr.size();
        for(size_t i = 0; i < len; ++i) 
        {
            if (i + 1 < len) 
            {
                if (arr[i] > arr[i + 1]) 
                {
                    big_values_arr.push_back(arr[i]);
                    small_values_arr.push_back(arr[i + 1]);
                } 
                else 
                {
                    big_values_arr.push_back(arr[i + 1]);
                    small_values_arr.push_back(arr[i]);
                }
                ++i;
            }
            else
                small_values_arr.push_back(arr[i]);
        }
        sortContainer(small_values_arr);
        for (typename T::iterator big_it = big_values_arr.begin(); big_it != big_values_arr.end(); ++big_it)
        {
            typename T::iterator insert_pos = std::upper_bound(small_values_arr.begin(), small_values_arr.end(), *big_it);
            small_values_arr.insert(insert_pos, *big_it);
        }
        return(small_values_arr);
    };
};

