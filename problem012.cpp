#include <iostream>
#include "common.h"
#include <cmath>
#include <cstdlib>
#include <cstring>
using namespace std;

int main()
{
    cout << "Finding primes" << endl;
    long max = 1e5;
    int h = 0;
    int *primes = getPrimes(max);
    int count = primeCount(max);
    long *factors = new long[max];
    cout << "Found primes" << endl;
    for(long n = 3, l = 3; ; n += l, l++)
    {
        long m = n;
        while (m > 1)
        {
            for (long i = 0; primes[i] <= m; i++)
            {
                if (primes[i] == 0)
                {
                    cout << "not enough primes" << endl;
                    exit(1);
                }
                if (m % primes[i] == 0)
                {
                    m /= primes[i];
                    factors[primes[i]]++;
                }
            }
        }
        long factor_count = 1;
        for (long i = 0; i != max; i++)
        {
            if (factors[i])
            {
                factor_count *= (factors[i] + 1);
                factors[i] = 0;
            }
        }
        if (factor_count > h)
        {
            h = factor_count;
            cout << n << " : " << factor_count << endl;
        }
        if(factor_count > 500)
        {
            exit(0);
        }
    }
}
