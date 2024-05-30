#pragma once

#include <iostream>
#include <cctype>
#include <sstream>
#include <stdlib.h>
#include <vector>
#include <limits>

// printValue.cpp

void printValue(const std::string &input);
void printValue(const char &value);
void printValue(const int &value);
void printValue(const float &value);
void printValue(const double &value);

// checkValue.cpp

bool hasF(const std::string &input);
bool hasDot(const std::string &input);

bool isSpecial(const std::string &input);
bool isChar(const std::string &input);
bool isInt(const std::string &input, int &output);
bool isFloat(std::string input, float &output);
bool isDouble(const std::string &input, double &output);
