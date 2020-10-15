#include <iostream>
#include "common.h"
using namespace std;
int main()
{
    bool *isPrime = getSieve(2e6);
    long sum = 0;
    for (int i = 0; i != 2e6; i++)
    {
        if (isPrime[i])
        {
            sum += i;
        }
    }
    cout << sum << endl;
}
