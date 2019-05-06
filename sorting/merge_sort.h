#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include <vector>
#include <iostream>
#include "../tests/common.h"

namespace {
    template <typename T>
    void merge(std::vector<T>& vec, int low, int mid, int hi) {
        std::vector<T> result;
        result.reserve(hi-low);

        int i = low;
        int j = mid;

        while (i < mid && j < hi) {
            if (vec[i] < vec[j]) {
                result.push_back(vec[i]);
                i++;
            } else {
                result.push_back(vec[j]);
                j++;
            }
        }

        while (i < mid) {
            result.push_back(vec[i]);
            i++;
        }

        while (j < hi) {
            result.push_back(vec[j]);
            j++;
        }

        // copy the sorted result into the original vector
        for (int i = low, j = 0; i < hi; i++, j++) {
            vec[i] = result[j];
        }
    }

    template <typename T>
    void _merge_sort(std::vector<T>& vec, int low, int hi) {
        if (hi - low < 2) {
            return;
        }

        int mid = (hi + low) / 2;
        _merge_sort(vec, low, mid);
        _merge_sort(vec, mid, hi);

        merge(vec, low, mid, hi);
    }
}

template <typename T>
void merge_sort(std::vector<T>& vec) {
    _merge_sort(vec, 0, vec.size());
}

#endif
