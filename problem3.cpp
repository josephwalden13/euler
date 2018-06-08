#include <iostream>
#include "common.h"
using namespace std;

int main()
{
    bool *isPrime = getSeive(100000);
    long long number = 600851475143;
    for (int i = 99999; i >= 0; i--)
    {
        if(isPrime[i] && number % i == 0)
        {
            cout << i << endl;
            break;
        }
    }
    delete isPrime;
}
