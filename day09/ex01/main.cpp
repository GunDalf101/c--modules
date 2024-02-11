#include "RPN.hpp"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <RPN expression>" << std::endl;
        return 1;
    }

    if (!evaluateRPN(argv[1])) {
        return 1;
    }
    return 0;
}
