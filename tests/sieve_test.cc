#include "catch.h"
#include "common.h"
#include "../sieves/sieve.h"

#include <chrono>

typedef std::vector<long long int> ReturnVector;

TEST_CASE("Testing prime sieves", "[sieve]") {
    SECTION("Testing on inputs 0, 1, -1 (should throw exceptions)") {
        CHECK_THROWS(eratosthenes(0));
        CHECK_THROWS(eratosthenes(1));
        CHECK_THROWS(eratosthenes(-1));
    }

    SECTION("Testing on input 2") {
        auto result = eratosthenes(2);
        CHECK(result.size() == 1);
        CHECK(result[0] == 2);
    }

    SECTION("Testing on input 10") {
        auto result = eratosthenes(10);
        REQUIRE(result.size() == 4);
        ReturnVector expected{2, 3, 5, 7};
        CHECK(result == expected);
    }

    SECTION("Testing on input 100") {
        auto result = eratosthenes(100);
        REQUIRE(result.size() == 25);
        // checking a few random primes for correctness
        CHECK(result[0] == 2);
        CHECK(result[4] == 11);
        CHECK(result[14] == 47);
        CHECK(result[result.size()-1] == 97);
    }

    SECTION("Testing on input 10,000,000") {
        auto result = eratosthenes(10000000);
        CHECK(result[0] == 2);
        CHECK(result[result.size()-1] == 9999991);
    }
}
