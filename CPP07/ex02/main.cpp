#include <iostream>
#include <Array.hpp>
#define MAX_VAL 750


int main(int, char**)
{
    std::cout << "initialising Array template and int * array with " << MAX_VAL << " elements" << std::endl;
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));

    std::cout << "Filling both arrays with random elements: " << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    std::cout << "First node template: " << numbers[0] << std::endl;
    std::cout << "First node template: " << numbers[MAX_VAL - 1] << std::endl;
    std::cout << "First node standart: " << mirror[0] << std::endl;
    std::cout << "First node standart: " << mirror[MAX_VAL - 1] << std::endl;

    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "Assigning new value to first node: " << std::endl;
    std::cout << "First node before: " << numbers[0] << std::endl;
    std::cout << "Second node before: " << numbers[1] << std::endl;
    if(numbers[0])
        numbers[0] = 0;
    else
        numbers[0] = 1;
    std::cout << "First node after: " << numbers[0] << std::endl;
    std::cout << "Second node after: " << numbers[1] << std::endl;

    delete [] mirror;//
    return 0;
}