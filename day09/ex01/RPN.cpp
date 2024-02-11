#include "RPN.hpp"

bool applyOperation(std::stack<int>& stack, const std::string& op) {
    if (stack.size() < 2) {
        std::cerr << "Error: Invalid expression" << std::endl;
        return false;
    }
    int rhs = stack.top(); stack.pop();
    int lhs = stack.top(); stack.pop();

    if (op == "+") stack.push(lhs + rhs);
    else if (op == "-") stack.push(lhs - rhs);
    else if (op == "*") stack.push(lhs * rhs);
    else if (op == "/") {
        if (rhs == 0) {
            std::cerr << "Error: Division by zero" << std::endl;
            return false;
        }
        stack.push(lhs / rhs);
    }
    return true;
}

bool parseToken(std::stack<int>& stack, const std::string& token) {
    if (token == "+" || token == "-" || token == "*" || token == "/") {
        return applyOperation(stack, token);
    } else {
        int number;
        if (!(std::istringstream(token) >> number)) {
            std::cerr << "Error: Invalid token '" << token << "'" << std::endl;
            return false;
        }
        stack.push(number);
    }
    return true;
}

bool evaluateRPN(const std::string& input) {
    std::istringstream iss(input);
    std::stack<int> stack;
    std::string token;
    while (iss >> token) {
        if (!parseToken(stack, token)) {
            return false;
        }
    }
    if (stack.size() != 1) {
        std::cerr << "Error: Invalid expression" << std::endl;
        return false;
    }
    std::cout << "Result: " << stack.top() << std::endl;
    return true;
}