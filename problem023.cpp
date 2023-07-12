//
// Created by Joseph Walden on 23/03/2023.
//

#include <cstdlib>
#include <cstdio>
#include <set>
#include <vector>
#include "primes.h"
#include <iostream>

using namespace std;

int sumFactors(vector<int> *primes, int number) {
    set<int> factors = set<int>();
    expandFactors(&factors, primes, number);
    cout << "Hello";
    int sum = 0;
    set<int>::iterator it = factors.begin();
    while(it != factors.end()) { 
        sum += *it;
        printf("p1\n");
        advance(it, factors.size() - 1);
        printf("p2\n");
    }
    return sum;
}

int main() {
    const int max = 28125;
    vector<int> primes = getPrimes(max);
    int *abundant = (int *) malloc(max * sizeof(int));
    for (int i = 0; i != max; i++) {
        abundant[i] = 0;
    }
    int index = 0;
    for (int i = 1; i != max; i++) {
        vector<int> primeFactors = getPrimeFactors(&primes, i);
        int sum = sumFactors(&primeFactors, i);
        if (sum > i) {
            abundant[index] = i;
            index = index + 1;
        }
    }
    long max_sum = 0;
    for (int i = 1; i != max; i++) {
        max_sum += i;
    }


    int abundant_sums[max + 1] = { 0 };
    for (int x = 0; x != index; x++) {
        for (int y = 0; y != index; y++) {
            int sum = (abundant[x] + abundant[y]);
            if (sum <= max) {
                abundant_sums[sum] = sum;
            }
        }
    }
    for(int i = 0; i != max; i++) { 
        max_sum -= abundant_sums[i];
    }

    printf("%ld\n", max_sum);
}