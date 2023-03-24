//
// Created by Joseph Walden on 23/03/2023.
//

#include "primes.h"
#include "vector"

using namespace std;


vector<int> getPrimes(int n) {
    vector<int> primes = {};
    int *sieve = (int *) malloc(n * sizeof(int));
    for (int i = 2; i != n; i++) {
        sieve[i] = 1;
    }
    sieve[0] = 0;
    sieve[1] = 0;

    for (int i = 2; i != n; i++) {
        if (sieve[i] == 1) {
            primes.push_back(i);
            for (int j = 2 * i; j < n; j += i) {
                sieve[j] = 0;
            }
        }
    }
    return primes;
}

vector<int> getPrimeFactors(vector<int> *primes, int number) {
    vector<int> factors = {};
    for (int i: *primes) {
        if (i > number / 2) {
            break;
        }
        if (number % i == 0) {
            factors.push_back(i);
        }
    }
    return factors;
}