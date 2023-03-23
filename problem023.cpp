//
// Created by Joseph Walden on 23/03/2023.
//

#include <cstdlib>
#include <cstdio>
#include <set>
#include <vector>

using namespace std;

vector<int> getPrimes(int n) {
    vector<int> primes = {};
    int* sieve = (int*)malloc(n * sizeof(int));
    for(int i = 2; i != n; i++) {
        sieve[i] = 1;
    }
    sieve[0] = 0;
    sieve[1] = 0;

    for(int i = 2; i != n; i++) {
        if(sieve[i] == 1) {
            primes.push_back(i);
            for(int j = 2 * i; j < n; j += i) {
                sieve[j] = 0;
            }
        }
    }
    return primes;
}

vector<int> getPrimeFactors(vector<int>* primes, int number) {
    vector<int> factors = {};
    for(int i : *primes) {
        if(i > number / 2) {
            break;
        }
        if(number % i == 0) {
            factors.push_back(i);
        }
    }
    return factors;
}

void expandFactors(set<int>* factors, vector<int>* primes, int n) {
    for(int i : *primes) {
        if(n % i == 0) {
            int f = n / i;
            (*factors).insert(f);
            if(f > 3) {
                expandFactors(factors, primes, f);
            }
        }
    }
}

int sumFactors(vector<int> *primes, int number) {
    set<int> factors = {};
    expandFactors(&factors, primes, number);
    int sum = 0;
    for(int i : factors) {
        sum += i;
    }
    return sum;
}

int main() {
    const int max = 28125;
    vector<int> primes = getPrimes(max);

    int* abundant = (int*)malloc(max * sizeof(int));
    for(int i = 0; i != max; i++) {
        abundant[i] = 0;
    }
    int index = 0;
    for(int i = 1; i != max; i++) {
        vector<int> primeFactors = getPrimeFactors(&primes, i);
        int sum = sumFactors(&primeFactors, i);
        if(sum > i) {
            abundant[index] = i;
            index = index + 1;
        }
    }
    long max_sum = 0;
    for(int i = 1; i <= max; i++) {
        max_sum += i;
    }


    int abundant_sums[max + 1];
    for(int i = 0; i <= max; i++) {
        abundant_sums[i] = 0;
    }
    for(int x = 0; x != index; x++) {
        for(int y = 0; y < index; y ++) {
            int sum = (abundant[x] + abundant[y]);
            if(sum <= max) {
                abundant_sums[sum] = sum;
            }
        }
    }
    for(int i : abundant_sums) {
        max_sum -= i;
    }

    printf("%ld\n", max_sum);
}