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
struct TypeName<std::vector<std::pair<int, int> > > 
{
    static std::string name() { return ("std::vector<std::pair<int, int> >"); }
};

template<>
struct TypeName<std::deque<std::pair<int, int> > >
{
    static std::string name() { return ("std::deque<std::pair<int, int> >"); }
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
    bool isDuplicate(const int &value, const T &arr)
    {
        for (typename T::const_iterator it = arr.begin(); it != arr.end(); ++it)
        {
            if (it->second == value)
                return true;
        }
        return false;
    }

    template<typename T>
    void parseInput(size_t ac, char **av, T &arr) 
    {
        for(size_t i = 1; i < ac; ++i)
        {
            std::istringstream sstream(av[i]);
            int value;
            sstream >> value;
            if(sstream.fail() || !sstream.eof() || value < 0)
                throw std::invalid_argument("Error: Not an positive integer");
            if (!isDuplicate(value, arr))  // No Duplicates!
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
            std::cout << it->second << ' ';
        }
        std::cout << std::endl;
    }

    std::vector<int> generateJacobsthalArray(int limit);

    template<typename T>
    size_t binarySearchValue(size_t cur_arr_pos, size_t inserted_count, int insert_value, const T &sorted_array)
    {
        size_t low = 0;
        size_t high = cur_arr_pos + inserted_count;
        size_t mid;
        while (low != high)
        {
            mid = low + ((high - low) / 2);
            if (insert_value < sorted_array[mid].second)
                high = mid;
            else 
                low = ++mid;
        }
        return (low);
    }

    template<typename T>
    int findInsertValue(const T &split_array, int corresponding_value)
    {
        size_t k = 0;
        while(split_array[k].second != corresponding_value)
            ++k;
        return (split_array[k].first);
    }

    template<typename T>
    void johnsonInsert(const T &split_array, T &sorted_array)
    {
        size_t split_len = split_array.size();
        std::vector<int> jacobsthal = generateJacobsthalArray(split_len);
        T sorted_copy = sorted_array;
        int inserted_count = 0;
        int insert_value;

        // handle within jacobsthal
        for (size_t i = 1; i < jacobsthal.size(); ++i) // jacobsthal: 0, 1, 1, 5, 11, 21, 43 ... n = (2x(n-2) + (n-1))
        {
            for (int j = (static_cast<int>(sorted_copy.size()) > jacobsthal[i] ? jacobsthal[i] - 1 : sorted_copy.size() - 1); j > jacobsthal[i - 1] - 1; --j) // from each jacobsnumber inseart backwards until previos jacobs number
            {
                insert_value = findInsertValue(split_array, sorted_copy[j].second);
                if (insert_value == -1)
                    continue;
                sorted_array.insert(sorted_array.begin() + binarySearchValue(j, inserted_count, insert_value, sorted_array), std::make_pair(-1, insert_value));
                ++inserted_count;
            }
        }
    } 

    template<typename T>
    void johnsonMerge(const T &array, T &split_array)
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
    void johnsonAlgorithm(const T &array, T &sorted_array)
    {
        T split_array;
        johnsonMerge(array, split_array);
        size_t split_array_size = split_array.size();
        if(split_array_size > 2)
            johnsonAlgorithm(split_array, sorted_array);
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
        johnsonInsert(split_array, sorted_array);
    }

    template<typename T>
    void johnsonSort(T &array)
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

        johnsonAlgorithm(array, sorted_array);
        array = sorted_array;
    }

};