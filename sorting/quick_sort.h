#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include <vector>
#include <algorithm>

namespace {
    template <typename T>
    T smart_pivot(std::vector<T>& vec, int low, int hi) {
        int mid = (low + hi) / 2;
        if (vec[mid] < vec[low]) {
            std::swap(vec[mid], vec[low]);
        }

        if (vec[hi] < vec[low]) {
            std::swap(vec[low], vec[hi]);
        }

        if (vec[mid] < vec[hi]) {
            std::swap(vec[mid], vec[hi]);
        }
        return vec[hi];
    }

    template <typename T>
    int partition(std::vector<T>& vec, int low, int hi) {
        //auto pivot = vec[low + (hi - low) / 2];
        auto pivot = smart_pivot(vec, low, hi);

        int i = low-1;
        int j = hi+1;

        while(i < j) {
            do {
                i++;
            } while(vec[i] < pivot);

            do {
                j--;
            } while(vec[j] > pivot);

            if (i < j) {
                std::swap(vec[i], vec[j]);
            }
        }

        return j;
    }

    template <typename T>
    void _quick_sort(std::vector<T>& vec, int low, int hi) {
        if (low < hi) {
            int p = partition(vec, low, hi);
            _quick_sort(vec, low, p);
            _quick_sort(vec, p+1, hi);
        }
    }
}

template <typename T>
void quick_sort(std::vector<T>& vec) {
    _quick_sort(vec, 0, vec.size()-1);
}

#endif
