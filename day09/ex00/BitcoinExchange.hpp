#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <cstdlib>
#include <climits>
#include <cctype>

std::map<std::string, double> readDataFromCSV(const std::string& filename);
std::string findClosestDate(const std::map<std::string, double>& csvMap, const std::string& date);
bool checkDate(const std::string& year, const std::string& month, const std::string& day);
bool checkValue(const std::string& value);
void processData(const std::map<std::string, double>& csvMap, std::istream& input);

#endif