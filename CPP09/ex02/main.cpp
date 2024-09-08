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

    std::vector<int> vec;
    pmerge.parseInput(ac, av, vec);
    pmerge.displayArr("Before:", vec);
    stop_time.first = clock();
    pmerge.johnsonSort(vec);
    stop_time.second = clock();
    pmerge.displayArr("After:", vec);
    pmerge.displayResults(stop_time, vec);

    std::deque<int> deq;
    pmerge.parseInput(ac, av, deq);
    // pmerge.displayArr("Before:", deq);
    stop_time.first = clock();
    pmerge.johnsonSort(deq);
    stop_time.second = clock();
    // pmerge.displayArr("After:", deq);
    pmerge.displayResults(stop_time, deq);

    std::list<int> lis;
    pmerge.parseInput(ac, av, lis);
    // pmerge.displayArr("Before:", lis);
    stop_time.first = clock();
    pmerge.johnsonSort(lis);
    stop_time.second = clock();
    // pmerge.displayArr("After:", lis);
    pmerge.displayResults(stop_time, lis);

/*     std::queue<int> que;
    pmerge.parseInput(ac, av, que);
    // pmerge.displayArr("Before:", que);
    stop_time.first = clock();
    pmerge.johnsonSort(que);
    stop_time.second = clock();
    // pmerge.displayArr("After:", que);
    pmerge.displayResults(stop_time, que);
    return (0); */
}