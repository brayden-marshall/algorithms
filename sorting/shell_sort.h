#ifndef SHELL_SORT_H
#define SHELL_SORT_H

#include <vector>
#include <algorithm>
#include <cmath>

typedef unsigned int uint;

namespace {
    // generate gaps < n as the sequence:
    //      4^k + 3 * 2^(k-1) + 1
    std::vector<uint> sedgewick_gaps(uint n) {
        std::vector<uint> gaps{1};

        int k = 1;
        uint gap;
        do {
            gap = pow(4, k) + (3 * pow(2, k-1)) + 1;
            gaps.push_back(gap);
            k++;
        } while(gap < n);

        return gaps;
    }
}

template <typename T>
void shell_sort(std::vector<T>& vec) {
    std::vector<uint> gaps = sedgewick_gaps(vec.size());

    for (auto gap : gaps) {
        for (uint i = gap; i < vec.size(); i++) {
            uint j = i;
            while (j >= gap && vec[j] < vec[j-gap]) {
                std::swap(vec[j], vec[j-1]);
                j -= gap;
            }
        }
    }
}

#endif
