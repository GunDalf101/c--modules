#include "BitcoinExchange.hpp"


std::map<std::string, double> readDataFromCSV(const std::string& filename) {
    std::ifstream file(filename.c_str());
    std::map<std::string, double> dataMap;

    if (!file.is_open()) {
        std::cerr << "Error opening file " << filename << std::endl;
        return dataMap;
    }

    std::string line;
    std::getline(file, line);

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string dateStr, rateStr;
        
        if (!(std::getline(iss, dateStr, ',')) || !(std::getline(iss, rateStr, ','))) {
            std::cerr << "Skipping line: Invalid format - " << line << std::endl;
            continue;
        }

        if (dateStr.size() != 10 || dateStr[4] != '-' || dateStr[7] != '-') {
            std::cerr << "Skipping line: Invalid date format - " << line << std::endl;
            continue;
        }

        double rate = atof(rateStr.c_str());
        if (rate == 0 && rateStr != "0") {
            std::cerr << "Skipping line: Invalid rate format - " << line << std::endl;
            continue;
        }

        dataMap[dateStr] = rate;
    }

    file.close();
    return dataMap;
}

std::string findClosestDate(const std::map<std::string, double>& csvMap, const std::string& date) {
    std::map<std::string, double>::const_iterator it = csvMap.find(date);
    if (it != csvMap.end()) {
        return it->first;
    }

    std::string closestDate;
    int minDifference = INT_MAX;

    int targetYear, targetMonth, targetDay;
    sscanf(date.c_str(), "%d-%d-%d", &targetYear, &targetMonth, &targetDay);

    for (it = csvMap.begin(); it != csvMap.end(); ++it) {
        int csvYear, csvMonth, csvDay;
        sscanf(it->first.c_str(), "%d-%d-%d", &csvYear, &csvMonth, &csvDay);

        int difference = (targetYear - csvYear) * 365 + (targetMonth - csvMonth) * 30 + (targetDay - csvDay);
        if (difference < minDifference && difference > 0) {
            minDifference = difference;
            closestDate = it->first;
        }
    }

    return closestDate;
}

bool checkDate(const std::string& year, const std::string& month, const std::string& day) {
    int yearInt = atoi(year.c_str());
    int monthInt = atoi(month.c_str());
    int dayInt = atoi(day.c_str());

    if (yearInt >= 2022) {
        if (monthInt >= 3 && dayInt >= 29)
            return false;
        if (monthInt > 3 || yearInt > 2022)
            return false;
    }

    if (yearInt <= 2009) {
        if (monthInt <= 1 && dayInt < 2)
            return false;
        if (monthInt < 1 || yearInt < 2009)
            return false;
    }

    if (monthInt > 12 || dayInt > 31)
        return false;
    if (monthInt % 2 == 0 && dayInt > 30)
        return false;
    if (yearInt % 4 == 0 && monthInt == 2 && dayInt > 29)
        return false;
    if (yearInt % 4 != 0 && monthInt == 2 && dayInt > 28)
        return false;
    if (dayInt < 1 || monthInt < 1)
        return false;

    return true;
}

bool checkValue(std::string& value) {
    size_t i = 0;
    int count = 0;
    if(value.length() < 1)
        return(false);
    if(value[i] == '-')
        i++;
    while(i < value.size())
    {
        if(std::isdigit(value[i]) == 0 && value[i] != '.')
            return(false);
        if(value[i] == '.')
            count++;
        if (count > 1)
            return(false);
        i++;
    }
    return(true);
}

void processData(const std::map<std::string, double>& csvMap, std::istream& input) {
    std::string line;
    std::getline(input, line);

    while (std::getline(input, line)) {
        std::istringstream iss(line);
        std::string dateStr, pipe, valueStr, afterPipe;
        
        iss >> dateStr >> pipe >> valueStr >> afterPipe;

        if (afterPipe.size() > 0 || pipe != "|" || !iss.eof()){
            std::cerr << "Skipping line: Invalid format - " << line << std::endl;
            continue;
        }
        
        if (dateStr == "date" || valueStr == "value") {
            continue;
        }

        if (dateStr.size() != 10 || dateStr[4] != '-' || dateStr[7] != '-') {
            std::cerr << "Skipping line: Invalid date format - " << line << std::endl;
            continue;
        }

        std::string year = dateStr.substr(0, 4);
        std::string month = dateStr.substr(5, 2);
        std::string day = dateStr.substr(8, 2);

        if (!checkDate(year, month, day)) {
            std::cerr << "Skipping line: Invalid date - " << line << std::endl;
            continue;
        }

        if (!checkValue(valueStr)) {
            std::cerr << "Skipping line: Invalid value format - " << line << std::endl;
            continue;
        }

        double value = atof(valueStr.c_str());
        if (value < 0)
        {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }
        
        if (value > 1000)
        {
            std::cerr << "Error: too big number." << std::endl;
            continue;
        }

        std::string closestDate = findClosestDate(csvMap, dateStr);
        std::map<std::string, double>::const_iterator csvIt = csvMap.find(closestDate);
        if (csvIt != csvMap.end()) {
            std::cout << "Date: " << dateStr << " " << csvIt->first << ", Value: " << value
                      << ", Rate from data.csv (closest date): " << csvIt->second * value << std::endl;
        }
    }
}
