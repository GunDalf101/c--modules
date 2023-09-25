#include <iostream>
#include <string>
#include <fstream>



int main(int ac, char** av){
    if (ac != 4)
        exit(0);
    std::string fileName = av[1];
    std::string s1 = "\n";
    std::string s2 = av[3];
    std::string line;
    std::ifstream inFile;
    inFile.open(fileName);

    if (!inFile){
        std::cerr << "Error: Cannot open input file." << std::endl;
        return 1;
    }

    std::ofstream outFile(fileName + ".replace");

    if (!outFile) {
        std::cerr << "Error: Cannot create or open output file." << std::endl;
        return 1;
    }

    // std::string fileContent((std::istreambuf_iterator<char>(inFile)), std::istreambuf_iterator<char>());
    
    std::string fileContent;
    getline(inFile, fileContent, '\0');

    inFile.close();

    std::string newLine;
    size_t pos = 0;
    size_t prevPos = 0;

    while ((pos = fileContent.find(s1, prevPos)) != std::string::npos) {
        newLine += fileContent.substr(prevPos, pos - prevPos) + s2;
        prevPos = pos + s1.length();
    }

    newLine += fileContent.substr(prevPos);

    outFile << newLine << std::endl;

    outFile.close();
}