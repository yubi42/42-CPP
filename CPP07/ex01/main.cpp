#include "iter.hpp"
#include <string>

int main()
{
    int arr[] = {1,2,3,4};
    iter(arr, sizeof(arr) / sizeof(arr[0]), &print<int>);

    std::string arr2[] = {"hi", "was", "geht"};
    iter(arr2, sizeof(arr2) / sizeof(arr2[0]), &print<std::string>);
}