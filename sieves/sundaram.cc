#include "sieve.h"

#include <vector>
#include <unordered_set>
#include <stdexcept>
#include <iostream>

std::vector<long long int> sundaram(long long int n) {
    if (n <= 1) {
        throw std::runtime_error("Sieve limit must be > 1");
    }

    // since sundaram finds primes up to 2n+2, we reduce n to
    // find only primes up to n
    n = (n-2) / 2;

    std::vector<bool> is_prime(n+1, true);
    std::vector<long long int> nums(n+1);
    for (long long int i = 1; i <= n; i++) {
        nums[i] = i;
    }

    for (long long int i = 1; i < n; i++) {
        for (long long int j = i; i + j + (2*i*j) <= n; j++) {
            is_prime[i+j+(2*i*j)] = false;
        }
    }

    std::vector<long long int> result;
    // sundaram does not account for prime=2, adding manually
    result.push_back(2);

    for (int i = 1; i <= n; i++) {
        if (is_prime[i]) {
            result.push_back(2*i + 1);
        }
    }

    return result;
}
