//
// Created by Joseph Walden on 23/03/2023.
//

/*
 * A perfect number is a number for which the sum of its proper divisors is exactly equal to the number.
 * For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28,
 *  which means that 28 is a perfect number.
 * A number n is called deficient if the sum of its proper divisors is less than n and it is called abundant
 *  if this sum exceeds n.
 * As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be written
 *  as the sum of two abundant numbers is 24. By mathematical analysis,
 *  it can be shown that all integers greater than 28123 can be written as the sum of two abundant numbers.
 * However, this upper limit cannot be reduced any further by analysis even though it is known that the
 *  greatest number that cannot be expressed as the sum of two abundant numbers is less than this limit.
 * Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.
 */

#include "stdlib.h"
#include "stdio.h"
#include <set>

int* getSieve(int n) {
    int* sieve = (int*)malloc(n * sizeof(int));
    for(int i = 2; i != n; i++) {
        sieve[i] = 1;
    }
    sieve[0] = 0;
    sieve[1] = 0;

    for(int i = 2; i != n; i++) {
        if(sieve[i] == 1) {
            for(int j = 2 * i; j < n; j += i) {
                sieve[j] = 0;
            }
        }
    }
    return sieve;
}

int getNPrimes(int* sieve, int n) {
    int count = 0;
    for(int i = 0; i != n; i++) {
        if(sieve[i] == 1) {
            count++;
        }
    }
    return count;
}

int* getPrimes(int* sieve, int n) {
    int* primes = (int*)malloc(getNPrimes(sieve, n) * sizeof(int));
    for(int i = 0, j = 0; i != n; i++) {
        if(sieve[i] == 1) {
            primes[j] = i;
            j++;
        }
    }
    return primes;
}

int getNPrimeFactors(int* primes, int number) {
    int end = 0;
    int count = 0;
    for(;primes[end] < number / 2;++end);
    for(int i = 0; i != end; i++) {
        if(number % primes[i] == 0) {
            count++;
        }
    }
    return count;
}

int* getPrimeFactors(int* primes, int number) {
    int end = 0;
    int* factors = (int*)malloc(getNPrimeFactors(primes, number) * sizeof(int));
    for(;primes[end] < number / 2;++end);
    for(int i = 0, j = 0; i != end; i++) {
        if(number % primes[i] == 0) {
            factors[j] = primes[i];
            j++;
        }
    }
    return factors;
}

void expandFactors(int* factors, int* factorIndex, int* primes, int nPrimes, int n) {
    for(int i = 0; i != nPrimes; i++) {
        if(n % primes[i] == 0) {
            int f = n / primes[i];
            factors[*factorIndex] = f;
            *factorIndex = *factorIndex + 1;
            if(f != 1) {
                expandFactors(factors, factorIndex, primes, nPrimes, f);
            }
        }
    }
}

int sumFactors(int* primes, int nPrimes, int number) {
    int* factors = (int*) malloc(number * sizeof(int));
    int sum = 0;
    for(int i = 0; i != number; i++) {
        factors[i] = 0;
    }
    int index = 0;
    expandFactors(factors, &index, primes, nPrimes, number);
    for(int i = 0; i != index; i++) {
        int dupe = 0;
        if(i >= 1) {
            for (int j = i - 1; j >= 0; j--) {
                if (factors[j] == factors[i]) {
                    dupe = 1;
                }
            }
        }
        if(dupe == 0) {
            sum += factors[i];
        }
    }
    return sum;
}

int main() {
    const int max = 28125;
    int* sieve = getSieve(max);
    int* primes = getPrimes(sieve, max);
    int* abundant = (int*)malloc(max * sizeof(int));
    for(int i = 0; i != max; i++) {
        abundant[i] = 0;
    }
    int index = 0;
    for(int i = 1; i != max; i++) {
        if(i%1000 == 0) {
            printf("Stage 1 - %d\n", i);
        }
        int nPrimeFactors = getNPrimeFactors(primes, i);
        int* primeFactors = getPrimeFactors(primes, i);
        int sum = sumFactors(primeFactors, nPrimeFactors, i);
        if(sum > i) {
            abundant[index] = i;
            index = index + 1;
        }
        delete primeFactors;
    }
    abundant = (int*)realloc(abundant, index * sizeof(int));
    std::set<int> abundant_sums = {};
    for(int x = 0; x != index; x++) {
        for(int y = 0; y != index; y++) {
            abundant_sums.insert(abundant[x] + abundant[y]);
        }
    }
    long sum = 0;
    for(int c = 0; c != max; c++) {
        if(std::find(abundant_sums.begin(), abundant_sums.end(), c) == abundant_sums.end()) {
            sum += c;
        }
    }
    printf("%ld\n", sum);
}