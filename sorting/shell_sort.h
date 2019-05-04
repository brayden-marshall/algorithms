#ifndef SHELL_SORT_H
#define SHELL_SORT_H

#include <vector>
#include <iterator> // for std::distance

// this algorithm is a translation of 
// https://en.wikipedia.org/wiki/Shellsort#Pseudocode
template <typename Iter>
void shell_sort(Iter first, Iter last) {
    std::vector<int> gaps = 
        sedgewick_gaps(std::distance(first, last));

    for (auto gap : gaps) {
        for (Iter i = first + gap; i < last; i++) {

            int temp = *i;
            Iter j = i;
            for (; j >= first+gap && *(j-gap) > temp; j -= gap) {
                *j = *(j-gap);
            }
            *j = temp;
        }
    }
}

#endif
