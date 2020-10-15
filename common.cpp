// common.cpp
//
#include <iostream>
#include <cstdlib>
#include <cstring>
#include "common.h"
#define LZZ_INLINE inline
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
    if (isPrime)
    {
        delete [] isPrime; //delete the sieve memory
    }
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
    if(isPrime)
    {
        delete [] isPrime; //delete sieve array
    }
    return primes; //return int array of primes
}
#undef LZZ_INLINE
