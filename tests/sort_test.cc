#include "catch.h"
#include "common.h"
#include "../sorting/slow_sort.h"
#include "../sorting/quick_sort.h"
#include "../sorting/merge_sort.h"

#include <vector>
#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()
#include <functional>
#include <string>

template <typename T>
using Iterator = typename std::vector<T>::iterator;

template <typename T>
struct Sorter {
    std::string name;
    std::function<void(Iterator<T>, Iterator<T>)> sort_function;
};

template <typename T>
bool approx_equal(const std::vector<T>& vec1, const std::vector<T>& vec2) {
    if (vec1.size() != vec2.size()) {
        return false;
    }

    for (int i = 0; i < vec1.size(); i++) {
        if (vec1[i] - vec2[i] > 0.0001) {
            return false;
        }
    }
    return true;
}

TEMPLATE_TEST_CASE("Testing Sorting Functions", "[sorting][vector]", int) {
    // setting up random number seed
    srand(static_cast<unsigned int>(time(0)));
    // throwing away first random number
    rand();

    std::vector<Sorter<TestType>> functions;
    functions.push_back(Sorter<TestType> {"insertion", insertion_sort<Iterator<TestType>>});
    functions.push_back(Sorter<TestType> {"selection", selection_sort<Iterator<TestType>>});
    functions.push_back(Sorter<TestType> {"bubble", bubble_sort<Iterator<TestType>>});
    functions.push_back(Sorter<TestType> {"quick", quick_sort<Iterator<TestType>>});
    functions.push_back(Sorter<TestType> {"merge", merge_sort<Iterator<TestType>>});

    for (auto func : functions) {
        SECTION("Testing " + func.name + " sort function") {

            SECTION("Should not affect empty list") {
                std::vector<TestType> vec1{}; 
                std::vector<TestType> vec2 = vec1;
                func.sort_function(vec1.begin(), vec1.end());
                CHECK(vec1 == vec2);
            }

            SECTION("Should not affect list with length 1") {
                std::vector<TestType> vec1{2}; 
                std::vector<TestType> vec2 = vec1;

                func.sort_function(vec1.begin(), vec1.end());
                CHECK(vec1 == vec2);
            }

            SECTION("Should not affect sorted list") {
                std::vector<TestType> vec1;
                for (int i = 0; i < 10; i++) {
                    vec1.push_back(i);
                }
                std::vector<TestType> vec2 = vec1;

                func.sort_function(vec1.begin(), vec1.end());
                CHECK(vec1 == vec2);
            }

            SECTION("Should work on list with duplicate values") {
                std::vector<TestType> vec {5, 2, 3, 7, 5, 3, 3, 2, 1};
                func.sort_function(vec.begin(), vec.end());
                CHECK(vector_is_sorted_asc(vec));
            }

            SECTION("Sorting a list with 10 elements") {
                std::vector<TestType> vec = {5, 6, 10, 4, 1, 2, 3, 7, 9, 8};
                func.sort_function(vec.begin(), vec.end());

                CHECK(vector_is_sorted_asc(vec));
            }

            SECTION("Sorting a list with 10 elements, starting in reverse order") {
                std::vector<TestType> vec;
                for (int i = 9; i >= 0; i--) {
                    vec.push_back(i);
                }

                func.sort_function(vec.begin(), vec.end());
                CHECK(vector_is_sorted_asc(vec));
            }

            SECTION("Sorting a list with 1000 random elements") {
                std::vector<TestType> vec;
                for (int i = 0; i < 1000; i++) {
                    int r = get_random_int(0, 100);
                    vec.push_back(r);
                }

                func.sort_function(vec.begin(), vec.end());
                CHECK(vector_is_sorted_asc(vec));
            }
        }
    }
}
