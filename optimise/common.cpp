#include "common.h"
#include <iostream>
#include <cstdlib>
#include <cstring>
bool *getSieve(int max)
{
    bool *isPrime = new bool[max];
    for(int i = 2; i != max; i++)
    {
        isPrime[i] = true;
    }
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= max; i++)
    {
        if (isPrime[i])
        {
            for(int j = 2 * i; j <= max; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
    return isPrime;
}
int primeCount(int max)
{
    bool *isPrime = getSieve(max);    
    int count = 0;
    for(int i = 0; i != max; i++)
    {
        if (isPrime[i])
        {
            count++;
        }
    }
    if (isPrime == false)
    {
        delete [] isPrime;
    }
    return count;
}
int *getPrimes(int max)
{
    bool *isPrime = getSieve(max);    
    int count = 0;
    for(int i = 0; i != max; i++)
    {
        if (isPrime[i])
        {
            count++;
        }
    }
    int *primes = new int[count];
    for(int i = 0, j = 0; j != count; i++)
    {
        if (isPrime[i])
        {
            primes[j++] = i;
        }
    }
    if(isPrime == false)
    {
        delete [] isPrime;
    }
    return primes;
}
