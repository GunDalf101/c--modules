#include "PmergeMe.hpp"
typedef std::pair<int, int> IntPair;

void insertPendElementsDeque(std::deque<int>& mainChain, std::deque<int>& pendElements) {
    std::vector<int> jacobsthal = generateJacobsthalUpToSize(pendElements.size() + 1);
    mainChain.insert(mainChain.begin(), pendElements[0]);

    for (size_t i = 0; i < jacobsthal.size(); ++i) {
        jacobsthal[i] -= 1;
        for (int j = jacobsthal[i]; j > jacobsthal[i - 1]; j--) {
            std::deque<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), pendElements[j]);
            mainChain.insert(it, pendElements[j]);
        }
    }

    
}

void mergeDeque(std::deque<IntPair>& arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    std::deque<IntPair> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0;
    int j = 0;
    int k = l;

    while (i < n1 && j < n2) {
        if (L[i].first <= R[j].first) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSortDeque(std::deque<IntPair>& arr, int l, int r) {
    if (l >= r) {
        return;
    }
    int m = l + (r - l) / 2;
    mergeSortDeque(arr, l, m);
    mergeSortDeque(arr, m + 1, r);
    mergeDeque(arr, l, m, r);
}

void fordJohnsonAlgoDeque(std::deque<int>& vec) {
    std::deque<IntPair> pairs;
    size_t size = vec.size();

    if (size == 1) {
        std::cout << vec[0] << std::endl;
        return;
    }

    int tmp = 0;
    if (size % 2 != 0) {
        tmp = vec[size - 1];
        size--;
    }
    for (size_t i = 0; i < size; i += 2) {
        IntPair pair;
        pair.first = vec[i];
        pair.second = vec[i + 1];
        pairs.push_back(pair);
    }

    for (size_t i = 0; i < pairs.size(); ++i) {
        if (pairs[i].first < pairs[i].second) {
            std::swap(pairs[i].first, pairs[i].second);
        }
    }

    mergeSortDeque(pairs, 0, pairs.size() - 1);

    vec.clear();

    for (size_t i = 0; i < pairs.size(); ++i) {
        vec.push_back(pairs[i].first);
    }

    std::deque<int> secondHalf;
    for (size_t i = 0; i < pairs.size(); ++i) {
        secondHalf.push_back(pairs[i].second);
    }
    insertPendElementsDeque(vec, secondHalf);

    if (tmp != 0) {
        std::deque<int>::iterator it = std::lower_bound(vec.begin(), vec.end(), tmp);
        vec.insert(it, tmp);
    }
}

std::vector<int> generateJacobsthalUpToSize(int maxSize) {
    std::vector<int> jacobsthal;
    jacobsthal.push_back(1);
    jacobsthal.push_back(3);
    for (int i = 2; jacobsthal[i - 1] < maxSize; i++) {
        jacobsthal.push_back(jacobsthal[i - 1] + 2 * jacobsthal[i - 2]);
    }
    jacobsthal.pop_back();
    jacobsthal.push_back(maxSize - 1);
    return jacobsthal;
}

void insertPendElements(std::vector<int>& mainChain, std::vector<int>& pendElements) {
    std::vector<int> jacobsthal = generateJacobsthalUpToSize(pendElements.size() + 1);
    mainChain.insert(mainChain.begin(), pendElements[0]);

    for (size_t i = 0; i < jacobsthal.size(); ++i) {
        jacobsthal[i] -= 1;
        for (int j = jacobsthal[i]; j > jacobsthal[i - 1]; j--) {
            std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), pendElements[j]);
            mainChain.insert(it, pendElements[j]);
        }
    }

    
}

void merge(std::vector<IntPair>& arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    std::vector<IntPair> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0;
    int j = 0;
    int k = l;

    while (i < n1 && j < n2) {
        if (L[i].first <= R[j].first) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(std::vector<IntPair>& arr, int l, int r) {
    if (l >= r) {
        return;
    }
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}

void fordJohnsonAlgoVec(std::vector<int>& vec) {
    std::vector<IntPair> pairs;
    size_t size = vec.size();

    if (size == 1) {
        std::cout << vec[0] << std::endl;
        return;
    }

    int tmp = 0;
    if (size % 2 != 0) {
        tmp = vec[size - 1];
        size--;
    }
    for (size_t i = 0; i < size; i += 2) {
        IntPair pair;
        pair.first = vec[i];
        pair.second = vec[i + 1];
        pairs.push_back(pair);
    }

    for (size_t i = 0; i < pairs.size(); ++i) {
        if (pairs[i].first < pairs[i].second) {
            std::swap(pairs[i].first, pairs[i].second);
        }
    }

    mergeSort(pairs, 0, pairs.size() - 1);

    vec.clear();

    for (size_t i = 0; i < pairs.size(); ++i) {
        vec.push_back(pairs[i].first);
    }

    std::vector<int> secondHalf;
    for (size_t i = 0; i < pairs.size(); ++i) {
        secondHalf.push_back(pairs[i].second);
    }
    insertPendElements(vec, secondHalf);

    if (tmp != 0) {
        std::vector<int>::iterator it = std::lower_bound(vec.begin(), vec.end(), tmp);
        vec.insert(it, tmp);
    }
}
