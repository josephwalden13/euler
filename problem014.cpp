#include <iostream>
using namespace std;
int cache[(int)1e6];
bool use_cache = true;
int collatz(long n, long c = 1)
{
    while(n != 1)
    {
        if (n < 1e6 && use_cache)
        {
            if (cache[n] != 0)
            {
                c += cache[n];
                break;
            }
        }
        c++;
        if (n&0x1)
        {
            n = (n << 1) + n + 1;
        }
        else
        {
            n = n >> 1;
        }
    }
    cache[n] = c;
    return c;
}
int main()
{
    int max[2] = {0, 0};
    for(int i = 1; i != 1e6; i++)
    {
        int c = collatz(i);
        
        if (c > max[1])
        {
            max[1] = c;
            max[0] = i;
        }
    }
    cout << max[0] << endl;
}
