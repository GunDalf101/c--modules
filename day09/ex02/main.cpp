#include "PmergeMe.hpp"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <number1> <number2> ..." << std::endl;
        return 1;
    }

    std::vector<int> numbersVector;
    std::deque<int> numbersDeque;
    srand(time(0));
    for (int i = 1; i < argc; i++) {
        int num = std::atoi(argv[i]);
        numbersVector.push_back(num);
        numbersDeque.push_back(num);
    }

    std::cout << "Unsorted Sequence: ";
    for (std::vector<int>::const_iterator it = numbersVector.begin(); it != numbersVector.end(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;

    std::clock_t vectorStart = std::clock();
    fordJohnsonAlgoVec(numbersVector);
    std::clock_t vectorEnd = std::clock();

    std::cout << "Sorted Vector: ";
    for (std::vector<int>::const_iterator it = numbersVector.begin(); it != numbersVector.end(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;

    double vectorElapsed = static_cast<double>(vectorEnd - vectorStart) / CLOCKS_PER_SEC * 1000;

    std::clock_t dequeStart = std::clock();
    fordJohnsonAlgoDeque(numbersDeque);
    std::clock_t dequeEnd = std::clock();

    std::cout << "Sorted Deque: ";
    for (std::deque<int>::const_iterator it = numbersDeque.begin(); it != numbersDeque.end(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;

    double dequeElapsed = static_cast<double>(dequeEnd - dequeStart) / CLOCKS_PER_SEC * 1000;
    std::cout << "Vector Sorting took " << vectorElapsed << " us." << std::endl;
    std::cout << "Deque Sorting took " << dequeElapsed << " us." << std::endl;

    // std::cout << std::boolalpha << std::is_sorted(numbersVector.begin(), numbersVector.end()) << std::endl;
    // std::cout << std::boolalpha << std::is_sorted(numbersDeque.begin(), numbersDeque.end()) << std::endl;

    return 0;
}
