#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <ctime>
#include <climits>

class BitcoinExchange
{
private:
    BitcoinExchange();
    BitcoinExchange(BitcoinExchange &src);
    BitcoinExchange& operator=(const BitcoinExchange& other);

    static void csv_to_map(std::ifstream &data_file, std::map<std::string, float> &csv, std::string &line);
    static bool check_format(std::ifstream &input_file, std::string &line);
    static void print_output(std::map<std::string, float> &csv, std::ifstream &input_file, std::string &line);
    static float calc_exchange(std::map<std::string, float> &csv, std::pair<std::string, float> &key_value);
    static bool date_validator(const std::string &date);
    static void set_tm(std::tm &tm, int &year, int &month, int &day);

public:
    static int exchange(std::ifstream &data_file, std::ifstream &input_file);
    virtual ~BitcoinExchange();
};

int error(std::string msg);
