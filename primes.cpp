//
// Created by Joseph Walden on 23/03/2023.
//

#include "primes.h"
#include "vector"
#include "set"
#include <iostream>

using namespace std;


vector<int> getPrimes(int n) {
    if(n == 1) {
        return vector<int>();
    }
    vector<int> primes = vector<int>();
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
    vector<int> factors = vector<int>();
    for(int i = 0; i != primes->size(); i++) { 
        if (primes->at(i) > number / 2) {
            continue;
        }
        if (number % primes->at(i) == 0) {
            factors.push_back(i);
        }
    }
    return factors;
}

void expandFactors(set<int> *factors, vector<int> *primes, int n) {
    // cout << primes << factors;
    vector<int>::iterator it = primes->begin();
    for(int i = 0; i != primes->size(); i++) {
        if (n % primes->at(i) == 0) {
            int f = n / primes->at(i);
            (*factors).insert(f);
            if (f > 3) {
                expandFactors(factors, primes, f);
            }
        }
    }
}

int LCM(int a, int b) {
    vector<int> primes = getPrimes(sqrt(max(a,b)) + 1);
    vector<int> primeA = getPrimeFactors(&primes, a);
    vector<int> primeB = getPrimeFactors(&primes, b);
    set<int> facA = set<int>();
    set<int> facB = set<int>();
    expandFactors(&facA, &primeA, a);
    expandFactors(&facB, &primeB, b);
    set<int>::iterator it = facA.begin();
    while (it != facA.end()) { 
        if (facB.find(*it) != facB.end()) { 
            return *it;
        }
        advance(it, facA.size());
    }

    if(b % a == 0) {
        return a;
    }
    else if (a % b == 0) {
        return b;
    }
    return 0;
}

bool *getSieve(int max) {
    bool *isPrime = new bool[max]; //allocate memory for boolean array
    for (int i = 2; i != max; i++) {
        isPrime[i] = true; //set values 2 - max to true
    }
    isPrime[0] = isPrime[1] = false; //set values 0 - 1 to false
    for (int i = 2; i <= max; i++) {
        if (isPrime[i]) //if i is a prime
        {
            for (int j = 2 * i; j <= max; j += i) {
                isPrime[j] = false; //set all multiples of i to false (not prime)
            }
        }
    }
    return isPrime;
}