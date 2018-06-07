#include <iostream>
using namespace std;
int main()
{
    bool *isPrime = new bool[100000];
    for(int i = 2; i != 100000; i++)
    {
        isPrime[i] = true;
    }
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= 100000; i++)
    {
        if (isPrime[i])
        {
            for(int j = 2 * i; j <= 100000; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
    long long number = 600851475143;
    for (int i = 99999; i >= 0; i--)
    {
        if(isPrime[i] && number % i == 0)
        {
            cout << i << endl;
            break;
        }
    } 
}
