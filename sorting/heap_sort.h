#ifndef HEAP_SORT_H
#define HEAP_SORT_H

#include <vector>
#include <algorithm>
#include <cmath>

namespace detail {
    int parent(int i) {
        return floor((i-1) / 2);
    }

    int left_child(int i) {
        return 2*i + 1;
    }

    int right_child(int i) {
        return 2*i + 2;
    }

    template <typename T>
    void sift_down(std::vector<T>& vec, int root, int end) {
        while (root < end) {
            int left = left_child(root);
            int right = right_child(root);
            int swap = root; 
            if (left < end && vec[left] > vec[swap]) {
                swap = left;
            }

            if (right < end && vec[right] > vec[swap]) {
                swap = right;
            }

            if (swap == root) {
                return;
            } else {
                std::swap(vec[swap], vec[root]);
            }

            root = swap;
        }
    }

    template <typename T>
    void heapify(std::vector<T>& vec) {
        int i = vec.size()-1;
        int end = vec.size();
        while (i >= 0) {
            sift_down(vec, i, end);
            i--;
        }
    }
}

template <typename T>
void heap_sort(std::vector<T>& vec) {
    detail::heapify(vec);

    for (int end = vec.size()-1; end > 0; end--) {
        std::swap(vec[0], vec[end]);
        detail::sift_down(vec, 0, end);
    }
}

#endif
