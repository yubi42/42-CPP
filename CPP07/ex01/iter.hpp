#pragma once
#include <iostream>

template <typename T, typename F>
void iter(T *arr, size_t arr_len, F f)
{
    for (size_t i = 0; i < arr_len; ++i)
    {
        f(arr[i]);
    }
}

template <typename T>
void print(T t)
{
    std::cout << t << std::endl;
}