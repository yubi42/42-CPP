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
        std::vector<std::pair<int, int> > lst;
        try
        {
        pmerge.parseInput(ac, av, lst);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            return 1;
        }
        pmerge.displayArr("Before:", lst);
        stop_time.first = clock();
        pmerge.johnsonSort(lst);
        stop_time.second = clock();
        pmerge.displayArr("After:", lst);
        pmerge.displayResults(stop_time, lst);
    }

    {
        std::deque<std::pair<int, int> > lst;
        pmerge.parseInput(ac, av, lst);  
        // pmerge.displayArrPairs("Before:", lst);
        stop_time.first = clock();
        pmerge.johnsonSort(lst);
        stop_time.second = clock();
        // pmerge.displayArrPairs("After:", lst);
        pmerge.displayResults(stop_time, lst);
    }

}