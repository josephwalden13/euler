#include <iostream>
#include "common.h"
#include <cmath>
using namespace std;
bool debug = true;
void debugOut(string s)
{
    if(debug)
    {
        cout << s << endl;
    }
}
bool *isPrime;
bool *getFactorsSieve(int number)
{
    int max = (number) + 1;
    int sq = sqrt(max) + 1;
    bool *isFactor = new bool[max];
    for (int i = 0; i != max; i++)
    {
        isFactor[i] = false;
    }
    isFactor[1] = isFactor[number] = true;
    for (int i = 2; i != sq; i++)
    {
        if (isPrime[i])
        {
            if (number % i == 0)
            {
                isFactor[i] = true; 
                for (int j = 2 * i; j < max; j+= i)
                {
                    if (number % j == 0)
                    {
                        isFactor[j] = true;
                    }
                } 
            }
        }
    }
    return isFactor;
}
int main()
{
    cout << "Finding primes" << endl;
    isPrime = getSieve(1000000000);
    cout << "Found primes" << endl;
    int top = 0;
    for(int number = 3, last = 3; ;number += last, last++)
    {
        int count = 0;
        bool *isFactor = getFactorsSieve(number);
        for (int i = 0; i != (number) + 1; i++)
        {
            if (isFactor[i])
            {
                count++;
            }
        }
        if (isFactor)
        {
            delete [] isFactor;
        }
        if (count > 500)
        {
            cout << number << endl;
            return 0;
        }
        if(count > top)
        {
            cout << number << "  " << count << endl;
            top = count;
        }   
    }
}
