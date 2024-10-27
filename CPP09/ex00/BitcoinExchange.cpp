#include <BitcoinExchange.hpp>

    BitcoinExchange::BitcoinExchange() {}
    BitcoinExchange::BitcoinExchange(BitcoinExchange &src) { (void)src; }
    BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) { (void)other; return *this; }
    BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::set_tm(std::tm &tm, int &year, int &month, int &day)
{
    tm.tm_year = year - 1900;
    tm.tm_mon = month - 1;
    tm.tm_mday = day;
    tm.tm_hour = 0;
    tm.tm_min = 0;
    tm.tm_sec = 0;
    tm.tm_isdst = 0;
    tm.tm_wday = 0;
    tm.tm_yday = 0;
    tm.tm_gmtoff = 0;
    tm.tm_zone = 0;
}

bool BitcoinExchange::date_validator(const std::string &date)
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-') 
        return (false);

    int year, month, day;
    char dash;
    std::istringstream dateStream(date);
    dateStream >> year >> dash >> month >> dash >> day;
    if (dateStream.fail())
        return false;

    std::tm tm;
    set_tm(tm, year, month, day);

    time_t raw_tm = std::mktime(&tm);
    if (raw_tm == -1)
        return (false);
    std::tm ref_tm = *std::localtime(&raw_tm);

    if (ref_tm.tm_year + 1900 != year || 
        ref_tm.tm_mon + 1 != month || 
        ref_tm.tm_mday != day)
        return (false);

    return (true);
}

float BitcoinExchange::calc_exchange(std::map<std::string, float> &csv, std::pair<std::string, float> &key_value)
{
    std::map<std::string, float>::iterator it = csv.begin();
    for(; it != csv.end() && it->first <= key_value.first; ++it){}
    if (it != csv.begin())
        --it;
    return(key_value.second * it->second);
    
}

void BitcoinExchange::print_output(std::map<std::string, float> &csv, std::ifstream &input_file, std::string &line)
{
    while(std::getline(input_file, line))
    {
        std::pair<std::string, float> key_value;
        std::istringstream line_stream(line);
        std::string token;
        std::getline(line_stream, key_value.first, ' ');
        if(!date_validator(key_value.first))
        {
            std::cout << "Error: bad input => " << key_value.first << std::endl;
            continue ;
        }
        std::getline(line_stream, token, ' ');
        line_stream >> key_value.second;
        if (line_stream.fail() || !line_stream.eof())
            std::cout << "Error: value invalid." << std::endl;
        if(key_value.second < 0)
            std::cout << "Error: not a positive number." << std::endl;
        else if(static_cast<long>(key_value.second) > INT_MAX)
            std::cout << "Error: too large a number." << std::endl;
        else 
            std::cout <<  key_value.first <<  " => " << key_value.second << " = " << calc_exchange(csv, key_value) << std::endl;
    }
}

void BitcoinExchange::csv_to_map(std::ifstream &data_file, std::map<std::string, float> &csv, std::string &line)
{
    std::getline(data_file, line);
    while(std::getline(data_file, line))
    {
        std::pair<std::string, float> key_value;
        std::istringstream line_stream(line);
        std::string token;
        std::getline(line_stream, token, ',');
        key_value.first = token;
        line_stream >> key_value.second;
        csv.insert(key_value);
    }
}

bool BitcoinExchange::check_format(std::ifstream &input_file, std::string &line)
{
    std::getline(input_file, line);
    std::istringstream line_stream(line);
    std::string token;
    std::getline(line_stream, token, '|');
    if (token != "date ")
        return false;
    std::getline(line_stream, token, '|');
    if (token != " value")
        return false;
    std::streampos list_start = input_file.tellg();
    while(std::getline(input_file, line))
    {
        if (line.find(" | ") == std::string::npos && line.find(" ") != std::string::npos)
            return (false);  
    }
    input_file.clear();
    input_file.seekg(list_start);
    return (true);
}


int BitcoinExchange::exchange(std::ifstream &data_file, std::ifstream &input_file)
{
    std::map<std::string, float> csv;
    std::string line;

    csv_to_map(data_file, csv, line);
    if(check_format(input_file, line))
        print_output(csv ,input_file, line);
    else
        return (error("Error: not the right format."));
    return (0);
}
