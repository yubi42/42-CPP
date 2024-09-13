#include <PmergeMe.hpp>

int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cerr << "Error: Please provide a sequence of positive integers." << std::endl;
        return(1);
    }

    PmergeMe pmerge;
    std::pair<clock_t, clock_t> stop_time;

    {
        std::vector<int> vec;
        pmerge.parseInput(ac, av, vec);
        pmerge.displayArr("Before:", vec);
        stop_time.first = clock();
        pmerge.johnsonSort(vec);
        stop_time.second = clock();
        pmerge.displayArr("After:", vec);
        std::cout << "johnson 1: use original vector for small values, new one to store big values << less memory usage but slower" << std::endl;
        std::cout << "johnson 2: 2 new vectors to store big and small values | using T::iterator" << std::endl;
        std::cout << "johnson 3: 2 new vectors to store big and small values | using size_t i << works for random access containers like vector and deque but not for list, map, set..." << std::endl;
        std::cout << "johnson 1: ";
        pmerge.displayResults(stop_time, vec);
    }
    {
        std::vector<int> vec;
        pmerge.parseInput(ac, av, vec);
        // pmerge.displayArr("Before:", vec);
        stop_time.first = clock();
        vec = pmerge.johnsonSort2(vec);
        stop_time.second = clock();
        // pmerge.displayArr("After:", vec);
        std::cout << "johnson 2: ";
        pmerge.displayResults(stop_time, vec);
    }
    {
        std::vector<int> vec;
        pmerge.parseInput(ac, av, vec);
        // pmerge.displayArr("Before:", vec);
        stop_time.first = clock();
        vec = pmerge.johnsonSort3(vec);
        stop_time.second = clock();
        // pmerge.displayArr("After:", vec);
        std::cout << "johnson 3: ";
        pmerge.displayResults(stop_time, vec);
    }
    {
        std::deque<int> deq;
        pmerge.parseInput(ac, av, deq);
        // pmerge.displayArr("Before:", deq);
        stop_time.first = clock();
        pmerge.johnsonSort(deq);
        stop_time.second = clock();
        // pmerge.displayArr("After:", deq);
        std::cout << "johnson 1: ";
        pmerge.displayResults(stop_time, deq);
    }
    {
        std::deque<int> deq;
        pmerge.parseInput(ac, av, deq);
        // pmerge.displayArr("Before:", deq);
        stop_time.first = clock();
        deq = pmerge.johnsonSort2(deq);
        stop_time.second = clock();
        // pmerge.displayArr("After:", deq);
        std::cout << "johnson 2: ";
        pmerge.displayResults(stop_time, deq);
    }
    {
        std::deque<int> deq;
        pmerge.parseInput(ac, av, deq);
        // pmerge.displayArr("Before:", deq);
        stop_time.first = clock();
        deq = pmerge.johnsonSort3(deq);
        stop_time.second = clock();
        // pmerge.displayArr("After:", deq);
        std::cout << "johnson 3: ";
        pmerge.displayResults(stop_time, deq);
    }
    {
        std::list<int> lis;
        pmerge.parseInput(ac, av, lis);
        // pmerge.displayArr("Before:", lis);
        stop_time.first = clock();
        pmerge.johnsonSort(lis);
        stop_time.second = clock();
        // pmerge.displayArr("After:", lis);
        std::cout << "johnson 1: ";
        pmerge.displayResults(stop_time, lis);
    }
    {
        std::list<int> lis;
        pmerge.parseInput(ac, av, lis);
        // pmerge.displayArr("Before:", lis);
        stop_time.first = clock();
        lis = pmerge.johnsonSort2(lis);
        stop_time.second = clock();
        // pmerge.displayArr("After:", lis);
        std::cout << "johnson 2: ";
        pmerge.displayResults(stop_time, lis);
    }

}