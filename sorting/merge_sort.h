#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include <vector>

// helper functions that the user does not need to access
namespace detail {
    template <typename Iter>
    std::vector<typename Iter::value_type> merge(const Iter start, const Iter mid, const Iter end) {
        std::vector<typename Iter::value_type> vec;
        vec.reserve(std::distance(start, end));
        auto left = start;
        auto right = mid;
        while (left != mid && right != end) {
            // push to the vector whichever value is smallest
            vec.push_back(*left < *right ? *left++ : *right++);
        }

        while(left < mid) {
            vec.push_back(*left);  
            left++;
        }

        while (right < end) {
            vec.push_back(*right);
            right++;
        }

        return vec;
    }
}

template <typename Iter>
void merge_sort(Iter first, Iter last) {
    auto size = std::distance(first, last);
    if (size < 2) {
        return;
    }
    
    // recursive call on left and right sections of the collection
    auto mid = std::next(first, size / 2);
    merge_sort(first, mid);
    merge_sort(mid, last);

    auto v = detail::merge(first, mid, last);
    std::move(v.cbegin(), v.cend(), first);
}

#endif
