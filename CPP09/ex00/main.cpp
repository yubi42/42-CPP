#include <BitcoinExchange.hpp>

int error(std::string msg)
{
    std::cerr << msg << std::endl;
    return (1);
}

int main (int ac, char **av)
{
    if (ac != 2)
        return (1);
    std::ifstream data_file("data.csv");
    if (ac != 2 || !data_file.is_open()) 
        return(error("Error: Could not open file."));

    std::ifstream input_file(av[1]);
    if (!input_file.is_open())
        return(error("Error: Could not open file."));

    return(BitcoinExchange::exchange(data_file, input_file));
}