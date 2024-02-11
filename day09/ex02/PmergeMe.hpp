#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <utility>

void fordJohnsonAlgoVec(std::vector<int>& vec);
void fordJohnsonAlgoDeque(std::deque<int>& vec);
std::vector<int> generateJacobsthalUpToSize(int maxSize);

#endif