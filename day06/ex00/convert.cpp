#include "convert.hpp"
#include <iostream>
#include <sstream>
#include <iomanip>

Convert::Convert(std::string const &str) : _str(str) {
}

Convert::Convert(Convert const &copy) : _str(copy.getStr()) {
}

Convert::~Convert() {
}

Convert &Convert::operator=(Convert const &copy) {
    if (this != &copy)
        *this = copy;
    return *this;
}

std::string const &Convert::getStr() const {
    return _str;
}

bool intOverflow(std::string &literal) {
    std::stringstream ss(literal);
    int i;
    ss >> i;
    std::stringstream ss2;
    ss2 << i;
    return ss2.str() == literal;
}

bool floatOverflow(std::string &literal) {
    std::stringstream ss(literal);
    float f;
    ss >> f;
    std::stringstream ss2;
    ss2 << std::fixed << f;
    return ss2.str() == literal;
}

bool doubleOverflow(std::string &literal) {
    std::stringstream ss(literal);
    double d;
    ss >> d;
    std::stringstream ss2;
    ss2 << std::fixed << d;
    return ss2.str() == literal;
}

bool isChar(std::string &literal) {
    std::stringstream ss(literal);
    double c;
    ss >> c;
    std::stringstream ss2;
    ss2 << c;
    return ss2.str() == literal;
}

void toChar(std::string &literal) {
    double c;
    std::stringstream ss(literal);
    try {
        ss >> c;
        if (!isChar(literal) || literal == "nanf" || literal == "nan" || literal == "inff" || literal == "+inff" || literal == "inf" || literal == "+inf" || literal == "-inff" || literal == "-inf")
            throw std::exception();
        if (c < 32 || c > 126)
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: '" << static_cast<char>(c) << "'" << std::endl;
    } catch (std::exception &e) {
        std::cout << "char: impossible" << std::endl;
    }
}

void toInt(std::string &literal) {
    double i;
    std::stringstream ss(literal);
    try {
        ss >> i;
        if (!intOverflow(literal))
            throw std::exception();
        std::cout << "int: " << static_cast<int>(i) << std::endl;
    } catch (std::exception &e) {
        std::cout << "int: impossible" << std::endl;
    }
}

void toFloat(std::string &literal) {
    double f;
    std::stringstream ss(literal);
    try {
        ss >> f;
        if (literal == "nanf" || literal == "nan")
            std::cout << "float: nanf" << std::endl;
        else if (literal == "inff" || literal == "+inff" || literal == "inf" || literal == "+inf")
            std::cout << "float: inff" << std::endl;
        else if (literal == "-inff" || literal == "-inf")
            std::cout << "float: -inff" << std::endl;
        else
            std::cout << "float: " << std::fixed << static_cast<float>(f) << "f" << std::endl;
    } catch (std::exception &e) {
        std::cout << "float: impossible" << std::endl;
    }
}

void toDouble(std::string &literal) {
    double d;
    std::stringstream ss(literal);
    try {
        ss >> d;
        if (literal == "nanf" || literal == "nan")
            std::cout << "float: nan" << std::endl;
        else if (literal == "inff" || literal == "+inff" || literal == "inf" || literal == "+inf")
            std::cout << "float: inf" << std::endl;
        else if (literal == "-inff" || literal == "-inf")
            std::cout << "float: -inf" << std::endl;
        else
            std::cout << "double: " << std::fixed << static_cast<double>(d) << std::endl;
    } catch (std::exception &e) {
        std::cout << "double: impossible" << std::endl;
    }
}

enum e_type {
    CHAR,
    INT,
    FLOAT,
    DOUBLE
};


int checkType(std::string &literal) {
    int type = 5;
    if (literal.length() == 1 && !isdigit(literal[0]))
        type = CHAR;
    else if (literal.find('.') == std::string::npos && intOverflow(literal))
        type = INT;
    else if (literal.find('f') != std::string::npos && floatOverflow(literal))
        type = FLOAT;
    else if (literal.find('.') != std::string::npos && doubleOverflow(literal))
        type = DOUBLE;
    return type;
}

void Convert::convert(std::string &literal) {
    int type = checkType(literal);

    std::stringstream ss(literal);
    switch (type) {
        case CHAR: {
            char c;
            ss >> c;
            literal = std::to_string(static_cast<int>(c));
            break;
        }
        case INT: {
            int i;
            ss >> i;
            literal = std::to_string(i);
            break;
        }
        case FLOAT: {
            float f;
            ss >> f;
            literal = std::to_string(f);
            break;
        }
        case DOUBLE: {
            double d;
            ss >> d;
            literal = std::to_string(d);
            break;
        }
    }

    toChar(literal);
    toInt(literal);
    toFloat(literal);
    toDouble(literal);
}

std::ostream &operator<<(std::ostream &out, Convert const &convert) {
    out << convert.getStr();
    return out;
}
