#include "sieve.h"

#include <cmath> // for sqrt
#include <stdexcept>

std::vector<long long int> eratosthenes(long long int n) {
    if (n <= 1) {
        throw std::runtime_error("Sieve input must be > 1");
    }

    std::vector<bool> is_prime(n, true);
    
    // sieve out composites
    for (long int i = 2; i <= floor(sqrt(n)); i++) {
        if (is_prime[i]) {
            for (long int j = i*i; j <= n; j+= i) {
                is_prime[j] = false;
            }
        }
    }

    // return the vector of only primes
    std::vector<long long int> primes;
    for (long long int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
    return primes;
}
