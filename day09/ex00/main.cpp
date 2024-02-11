#include "BitcoinExchange.hpp"

int main() {
    std::ifstream input_file("input.txt");
    if (!input_file.is_open()) {
        std::cerr << "Error opening input file" << std::endl;
        return 1;
    }

    std::map<std::string, double> csvMap = readDataFromCSV("data.csv");
    processData(csvMap, input_file);
    input_file.close();

    return 0;
}
