#pragma once

#include <stdexcept>
#include <iostream>
#include <cstdlib>

template <typename T>
class Array 
{
    private:
        unsigned int _len;
        T* _arr;
    
    public:
        Array() : _len(0), _arr(NULL) 
        {
            std::cout << "Empty array created" << std::endl;
        }

        explicit Array(unsigned int n) : _len(n), _arr(new T[n])
        {
            for(unsigned int i = 0; i < _len; ++i)
                _arr[i] = T();
            std::cout << "Array with " << _len << " elements created" << std::endl;
        }

        Array(const Array &src) : _len(src._len), _arr(new T[src._len]) 
        {
            for(unsigned int i = 0; i < _len; ++i)
                _arr[i] = src._arr[i];
            std::cout << "Array copy with " << _len << " elements created" << std::endl;
        }

        Array &operator=(const Array &src)
        {
            if (this == &src)
                return (*this);
            delete[] _arr;
            _len = src._len;
            _arr = new T[_len];
            for(unsigned int i = 0; i < _len; ++i)
                _arr[i] = src._arr[i];
            std::cout << "Array copied with " << _len << " elements" << std::endl;
            return (*this);
        }

        T &operator[](unsigned int i)
        {
            if (i >= _len)
                throw std::out_of_range("Index out of range");
            return (_arr[i]);
        }

        T &operator[](unsigned int i) const
        {
            if (i >= _len)
                throw std::out_of_range("Index out of range");
            return (_arr[i]);
        }

        ~Array() 
        {
            std::cout << "Array deleted" << std::endl;
            delete[] _arr;
        }

        unsigned int size() const {return _len;}
};

