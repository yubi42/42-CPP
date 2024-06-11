#pragma once
#include <iostream>

template <typename T>
void easyfind(T *arr, int num)
{
    size_t arr_len = sizeof(arr) / sizeof(arr[0]);
    for (size_t i = 0; i < arr_len; ++i)
    {
        if (arr[i] == num)
            return (i);
    }
    return (i);
}