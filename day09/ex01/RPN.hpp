#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>

bool applyOperation(std::stack<int>& stack, const std::string& op);
bool parseToken(std::stack<int>& stack, const std::string& token);
bool evaluateRPN(const std::string& input);

#endif