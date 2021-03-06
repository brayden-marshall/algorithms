#ifndef SLOW_SORT_H
#define SLOW_SORT_H

#include <vector>
#include <algorithm>

typedef unsigned int uint;

// Insertion sort
template <typename T>
void insertion_sort(std::vector<T>& vec) {
    for (uint i = 0; i < vec.size(); i++) {
        uint j = i;
        while (j > 0 && vec[j] < vec[j-1]) {
            std::swap(vec[j], vec[j-1]);
            j--;
        }
    }
}

// Selection sort
template <typename T>
void selection_sort(std::vector<T>& vec) {
    for (uint i = 0; i < vec.size(); i++) {
        uint min_index = i;
        for (uint j = i; j < vec.size(); j++) {
            if (vec[j] < vec[min_index]) {
                min_index = j;
            }
        }
        std::swap(vec[min_index], vec[i]);
    }
}

// Bubble sort
template <typename T>
void bubble_sort(std::vector<T>& vec) {
    bool sorted = false;
    while (!sorted) {
        sorted = true;
        for (uint i = 1; i < vec.size(); i++) {
            if (vec[i-1] > vec[i]) {
                std::swap(vec[i-1], vec[i]);
                sorted = false;
            }
        }
    }
}

// Cocktail sort
template <typename T>
void cocktail_sort(std::vector<T>& vec) {
    bool sorted = vec.size() <= 1;
    uint low = 0;
    uint hi = vec.size()-1;
    while (!sorted) {
        sorted = true;

        // bubble sort going up
        for (uint i = low; i < hi; i++) {
            if (vec[i] > vec[i+1]) {
                std::swap(vec[i], vec[i+1]);
                sorted = false;
            }
        }
        hi--;

        if (sorted) {
            break;
        }

        // bubble sort going down
        for (uint i = hi; i > low; i--) {
            if (vec[i] < vec[i-1]) {
                std::swap(vec[i], vec[i-1]);
                sorted = false;
            }
        }
        low++;
    }
}

// Comb sort
template <typename T>
void comb_sort(std::vector<T>& vec) {
    const double shrink_factor = 1.3;
    uint gap = vec.size();
    bool sorted = false;

    while (!sorted) {
        gap = gap / shrink_factor;
        if (gap <= 1) {
            gap = 1;
            sorted = true;
        }

        for (uint i = 0; i + gap < vec.size(); i++) {
            if (vec[i] > vec[i+gap]) {
                std::swap(vec[i], vec[i+gap]);
                sorted = false;
            }
        }
    }
}

// Gnome sort
template <typename T>
void gnome_sort(std::vector<T>& vec) {
    uint i = 0;
    while (i < vec.size()) {
        if (i > 0 && vec[i] < vec[i-1]) {
            std::swap(vec[i], vec[i-1]);
            i--;
        } else {
            i++;
        }
    }
}

// Odd-Even sort
template <typename T>
void odd_even_sort(std::vector<T>& vec) {
    bool sorted = vec.size() <= 1;
    while(!sorted) {
        sorted = true;
        for (uint i = 1; i < vec.size()-1; i+= 2) {
            if (vec[i] > vec[i+1]) {
                std::swap(vec[i], vec[i+1]);
                sorted = false;
            }
        }

        for (uint i = 0; i < vec.size()-1; i+= 2) {
            if (vec[i] > vec[i+1]) {
                std::swap(vec[i], vec[i+1]);
                sorted = false;
            }
        }
    }
}

// Cycle sort
template <typename T>
void cycle_sort(std::vector<T>& vec) {

    uint i = 0;
    while (i < vec.size()) {

        // determine the value's final position
        uint final_position = 0;
        for (uint j = 0; j < vec.size(); j++) {
            if (vec[j] < vec[i]) {
                final_position++;
            }
        }

        // insert after any duplicates
        while (i != final_position && vec[i] == vec[final_position]) {
            final_position++;
        }

        // swap value into it's final position, or move to next value
        if (final_position != i) {
            std::swap(vec[i], vec[final_position]);
        } else {
            i++;
        }
    }
}

#endif
