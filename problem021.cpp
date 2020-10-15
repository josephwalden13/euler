#include <iostream>

int factor_cache[100000];
int factor_sum(int n)
{
    if(factor_cache[n] > -1)
    {
        return factor_cache[n];
    }
    int sum = 0;
    int factors[10001];

    for(int i = 0; i != 10001; i++)
    {
        factors[i] = 1;
    }
    for(int i = 1; i != 10001 && i <= (n / 2) + 1; i++)
    {
        if(factors[i])
        {
            if(n % i != 0)
            {
                for(int j = i; j <= 10000; j+=i)
                {
                    factors[j] = 0;
                }
            }
            else
            {
                sum += i;
            }
        }
    }
    factor_cache[n] = sum;
    return sum;
}
int amicable(int n)
{
    int i = factor_sum(n);
    return n == i? false : (factor_sum(i) == n)? i : 0;
}
int problem21()
{
    for(int i = 0; i != 100000; i++)
    {
        factor_cache[i] = -1;
    }
    int sum = 0;
    for(int i = 0; i != 10001; i++)
    {
        int j = amicable(i);
        if(j)
        {
            sum += i;
        }
    }
    return sum;
}

using namespace std;
int main()
{
    cout << problem21() << endl;
}
