#ifndef COMMON_H
#define COMMON_H

#include <vector>
#include <iostream>

template <typename T>
void print_vector(const std::vector<T>& vec) {
    std::cout << "[";
    for (int i = 0; i < vec.size(); i++) {
        if (i == 0) {
            std::cout << vec[i];
        } else {
            std::cout << ", " << vec[i];
        }
    }
    std::cout << "]\n";
}

template <typename T>
bool vector_is_sorted_asc(const std::vector<T>& vec) {
    for (long unsigned int i = 1; i < vec.size(); i++) {
        if (vec[i-1] > vec[i]) {
            return false;
        }
    }
    return true;
}

// assumes that srand() has already been called
int get_random_int(int min, int max);

#endif
