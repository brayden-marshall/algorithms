#ifndef SLOW_SORT_H
#define SLOW_SORT_H

#include <vector>
#include <algorithm>

/* This header contains all of the slow sorting algorithms
 *     - insertion
 *     - selection
 *     - bubble
 *     - cocktail
 *     - comb
 *     - gnome
 *     - odd-even
 */

// Insertion sort
template <typename Iter>
void insertion_sort(Iter first, Iter last) {
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
        Iter min = i;
        for (Iter j = i; j != last; j++) {
            if (*j < *min) {
                min = j;
            }
        }
        std::iter_swap(i, min);
    }
}

/****************************
 * Bubble Sort and variants *
 ***************************/

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

// Cocktail sort
template <typename Iter>
void cocktail_sort(Iter first, Iter last) {
    if (std::distance(first, last) <= 1) {
        return;
    }

    // last-- to not go out of bounds
    last--;
    bool sorted = false;
    while (!sorted) {
        sorted = true;

        // bubble sort going up
        for (Iter i = first; i < last; i++) {
            if (*i > *(i+1)) {
                std::iter_swap(i, i+1);
                sorted = false;
            }
        }
        last--;

        if (sorted) {
            break;
        }

        // bubble sort going down
        for (Iter i = last; i >= first; i--) {
            if (*i > *(i+1)) {
                std::iter_swap(i, i+1);
                sorted = false;
            }
        }
        first++;
    }
}

// Comb sort
template <typename Iter>
void comb_sort(Iter first, Iter last) {
    const double shrink_factor = 1.3;
    int gap = std::distance(first, last);
    bool sorted = false;

    while (!sorted) {
        gap = gap / shrink_factor;
        if (gap <= 1) {
            gap = 1;
            sorted = true;
        }

        for (Iter i = first; i + gap < last; i++) {
            if (*i > *(i + gap)) {
                std::iter_swap(i, i+gap);
                sorted = false;
            }
        }
    }
}

// Gnome sort
template <typename Iter>
void gnome_sort(Iter first, Iter last) {
    Iter i = first;
    while (i != last) {
        if (*i < *(i-1)) {
            std::iter_swap(i, i-1);
            i--;
        } else {
            i++;
        }
    }
}

// Odd-even sort
template <typename Iter>
void odd_even_sort(Iter first, Iter last) {

    if (std::distance(first, last) <= 1) {
        return;
    }

    bool sorted = false;
    while (!sorted) {
        sorted = true;
        for (Iter i = first+1; i < last-1; i += 2) {
            if (*i > *(i+1)) {
                std::iter_swap(i, i+1);
                sorted = false;
            }
        }

        for (Iter i = first; i < last; i += 2) {
            if (*i > *(i+1)) {
                std::iter_swap(i, i+1);
                sorted = false;
            }
        }

    }
}

#endif
