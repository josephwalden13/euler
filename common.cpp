// common.cpp
//
#include <iostream>
#include "common.h"
#include "vector"

using namespace std;

bool * getSieve (int max)
{
    bool *isPrime = new bool[max]; //allocate memory for boolean array
    for(int i = 2; i != max; i++)
    {
        isPrime[i] = true; //set values 2 - max to true
    }
    isPrime[0] = isPrime[1] = false; //set values 0 - 1 to false
    for (int i = 2; i <= max; i++)
    {
        if (isPrime[i]) //if i is a prime
        {
            for(int j = 2 * i; j <= max; j += i)
            {
                isPrime[j] = false; //set all multiples of i to false (not prime)
            }
        }
    }
    return isPrime;
}
int primeCount (int max)
{
    bool *isPrime = getSieve(max); //allocate memory for prime sieve
    int count = 0;
    for(int i = 0; i != max; i++)
    {
        if (isPrime[i])
        {
            count++; //for each prime increment count
        }
    }
    delete [] isPrime; //delete the sieve memory
    return count; //return number of primes
}
int * getPrimes (int max)
{
    bool *isPrime = getSieve(max); //allocate memory for prime sieve
    int count = 0;
    for(int i = 0; i != max; i++)
    {
        if (isPrime[i])
        {
            count++; //for each prime increment count
        }
    }
    int *primes = new int[count]; //allocate memory for prime array
    for(int i = 0, j = 0; j != count; i++)
    {
        if (isPrime[i])
        {
            primes[j++] = i; //add i to primes at index, j, and increment index, j.
        }
    }
    delete [] isPrime; //delete sieve array
    return primes; //return int array of primes
}

vector<int> getPrimes_vector(int n) {
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
#undef LZZ_INLINE
