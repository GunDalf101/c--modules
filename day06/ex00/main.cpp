#include "convert.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Usage: ./convert <string>" << std::endl;
        return 1;
    }
    Convert convert(argv[1]);
    std::string literal = convert.getStr();
    convert.convert(literal);
    return 0;
}