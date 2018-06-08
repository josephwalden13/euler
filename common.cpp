#include "common.h"
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
