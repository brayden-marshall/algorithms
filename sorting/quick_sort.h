#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include <algorithm>
#include <iostream>

// helper functions that the user does not need to access
namespace detail {
    // gets the median of the first, last and middle elements
    template <typename Iter>
    Iter smart_pivot(Iter low, Iter hi) {
        Iter mid = low + (hi - low) / 2;
        if (*mid < *low) {
            std::iter_swap(mid, low);
        }
        if (*hi < *low) {
            std::iter_swap(hi, low);
        }

        if (*mid < *hi) {
            std::iter_swap(hi, mid);
        }
        return hi;
    }

    template <typename Iter>
    Iter partition(Iter low, Iter hi) {
        auto pivot = *(smart_pivot(low, hi));
        Iter i = low-1;
        Iter j = hi+1;
        while (i < j) {
            do {
                i++;
            } while(*i < pivot);

            do {
                j--;
            } while(*j > pivot);

            if (i < j) {
                std::iter_swap(i, j);
            }
        }
        return j;
    }

    template <typename Iter>
    void _quick_sort(Iter first, Iter last) {
        if (first < last) {
            Iter p = partition(first, last);
            _quick_sort(first, p);
            _quick_sort(p + 1, last);
        }
    }
}

template <typename Iter>
void quick_sort(Iter first, Iter last) {
    if (first < last) {
        last--;
        detail::_quick_sort(first, last);
    }
}

#endif
