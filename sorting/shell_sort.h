#ifndef SHELL_SORT_H
#define SHELL_SORT_H

#include <vector>
#include <iterator> // for std::distance

// this algorithm is a translation of 
// https://en.wikipedia.org/wiki/Shellsort#Pseudocode
template <typename Iter>
void shell_sort(Iter first, Iter last) {
    std::vector<int> gaps = {701, 301, 132, 57, 23, 10, 4, 1};

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
