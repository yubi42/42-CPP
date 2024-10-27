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
        try
        {
        pmerge.parseInput(ac, av, vec);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            return 1;
        }        
        pmerge.displayArr("Before:", vec);
        stop_time.first = clock();
        pmerge.johnsonSort(vec);
        stop_time.second = clock();
        pmerge.displayArr("After:", vec);
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
        pmerge.displayResults(stop_time, deq);
    }
    {
        std::list<int> lst;
        pmerge.parseInput(ac, av, lst);  
        // pmerge.displayArr("Before:", lst);
        stop_time.first = clock();
        pmerge.johnsonSort(lst);
        stop_time.second = clock();
        // pmerge.displayArr("After:", lst);
        pmerge.displayResults(stop_time, lst);
    }
    std::cout << "for testing with 1 arr of pairs instead of 2 arr:" << std::endl;
    {
        std::vector<std::pair<int, int> > lst;
        pmerge.parseInputPairs(ac, av, lst);  
        // pmerge.displayArrPairs("Before:", lst);
        stop_time.first = clock();
        pmerge.johnsonSortPairs(lst);
        stop_time.second = clock();
        // pmerge.displayArrPairs("After:", lst);
        pmerge.displayResults(stop_time, lst);
    }
    {
        std::deque<std::pair<int, int> > lst;
        pmerge.parseInputPairs(ac, av, lst);  
        // pmerge.displayArrPairs("Before:", lst);
        stop_time.first = clock();
        pmerge.johnsonSortPairs(lst);
        stop_time.second = clock();
        // pmerge.displayArrPairs("After:", lst);
        pmerge.displayResults(stop_time, lst);
    }
    {
        std::list<std::pair<int, int> > lst;
        pmerge.parseInputPairs(ac, av, lst);  
        // pmerge.displayArrPairs("Before:", lst);
        stop_time.first = clock();
        pmerge.johnsonSortPairs(lst);
        stop_time.second = clock();
        // pmerge.displayArrPairs("After:", lst);
        pmerge.displayResults(stop_time, lst);
    }
}