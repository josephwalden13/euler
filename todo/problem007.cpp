#include <iostream>
#include "common.h"
using namespace std;
int main()
{
    bool *isPrime = getSieve(1000000);
    for (int i = 0, j = 0; ; i++)
    {
        if (isPrime[i])
        {
            j++;
            if (j == 10001)
            {  
                cout << i << endl;
                break;
            }
        }
    }
    delete [] isPrime;
}
