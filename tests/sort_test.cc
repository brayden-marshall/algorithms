#include "catch.h"
#include "common.h"
#include "../sorting/slow_sort.h"
#include "../sorting/quick_sort.h"
#include "../sorting/merge_sort.h"
#include "../sorting/shell_sort.h"

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
    std::function<void(std::vector<T>&)> sort_function;
};

TEMPLATE_TEST_CASE("Testing Sorting Functions", "[sorting][vector]", int) {
    // setting up random number seed
    srand(static_cast<unsigned int>(time(0)));
    // throwing away first random number
    rand();

    std::vector<Sorter<TestType>> functions;
    functions.push_back(Sorter<TestType> {"insertion", insertion_sort<TestType>});
    functions.push_back(Sorter<TestType> {"shell", shell_sort<TestType>});
    functions.push_back(Sorter<TestType> {"selection", selection_sort<TestType>});
    functions.push_back(Sorter<TestType> {"bubble", bubble_sort<TestType>});
    functions.push_back(Sorter<TestType> {"cocktail", cocktail_sort<TestType>});
    functions.push_back(Sorter<TestType> {"comb", comb_sort<TestType>});
    functions.push_back(Sorter<TestType> {"gnome", gnome_sort<TestType>});
    functions.push_back(Sorter<TestType> {"odd_even", odd_even_sort<TestType>});
    functions.push_back(Sorter<TestType> {"quick", quick_sort<TestType>});
    functions.push_back(Sorter<TestType> {"merge", merge_sort<TestType>});

    for (auto func : functions) {
        SECTION("Testing " + func.name + " sort function") {

            SECTION("Should not affect empty list") {
                std::vector<TestType> vec{}; 
                std::vector<TestType> expected = vec;
                func.sort_function(vec);
                CHECK(vec == expected);
            }

            SECTION("Should not affect list with length 1") {
                std::vector<TestType> vec{2}; 
                std::vector<TestType> expected = vec;

                func.sort_function(vec);
                CHECK(vec == expected);
            }

            SECTION("Should not affect sorted list") {
                std::vector<TestType> vec;
                for (int i = 0; i < 10; i++) {
                    vec.push_back(i);
                }
                std::vector<TestType> expected = vec;

                func.sort_function(vec);
                CHECK(vec == expected);
            }

            SECTION("Should work on list with duplicate values") {
                std::vector<TestType> vec {5, 2, 3, 7, 5, 3, 3, 2, 1};
                std::vector<TestType> expected {1, 2, 2, 3, 3, 3, 5, 5, 7};
                func.sort_function(vec);
                CHECK(vec == expected);
            }

            SECTION("Sorting a list with 10 elements") {
                std::vector<TestType> vec = {5, 6, 10, 4, 1, 2, 3, 7, 9, 8};
                std::vector<TestType> expected = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
                func.sort_function(vec);

                CHECK(vec == expected);
            }

            SECTION("Sorting a list with 10 elements, starting in reverse order") {
                std::vector<TestType> vec;
                std::vector<TestType> expected;
                for (int i = 9; i >= 0; i--) {
                    vec.push_back(i);
                    expected.push_back(9-i);
                }

                func.sort_function(vec);
                CHECK(vec == expected);
            }

            SECTION("Sorting a list with 30 random elements") {
                std::vector<TestType> vec;
                for (int i = 0; i < 30; i++) {
                    int r = get_random_int(0, 100);
                    vec.push_back(r);
                }
                std::vector<TestType> expected = vec;
                std::sort(expected.begin(), expected.end());

                func.sort_function(vec);
                CHECK(vec == expected);
            }
        }
    }
}
