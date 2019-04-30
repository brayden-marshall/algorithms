#ifndef SLOW_SORT_H
#define SLOW_SORT_H

#include <vector>
#include <algorithm>

/* This header contains all of the slow sorting algorithms
 *     - insertion
 *     - selection
 *     - bubble
 *
 * These algorithms are included for completeness and benchmarking purposes,
 * not to be used in real applications (without extremely good reason)
 */

// Insertion sort
template <typename Iter>
void insertion_sort(Iter first, Iter last) {
    // iterate through every element
    for (Iter i = first; i != last; i++) {
        for (Iter j = i; *j < *(j-1); j--) {
            std::iter_swap(j, j-1);
        }
    }
}

// Selection sort
template <typename Iter>
void selection_sort(Iter first, Iter last) {
    for (Iter i = first; i != last; i++) {
        std::iter_swap(i, std::min_element(i, last));
    }
}

// Bubble sort
template <typename Iter>
void bubble_sort(Iter first, Iter last) {
    for (Iter i = first; i != last; i++) {
        for (Iter j = first; j < i; j++) {
            if (*i < *j) {
                std::iter_swap(i, j);
            }
        }
    }
}

#endif
