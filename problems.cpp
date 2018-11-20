#include <iostream>

int problem21();

using namespace std;
int main()
{
    cout << "Project Euler solutions by Joseph Walden\n";
    cout << "Enter a problem (x>21): ";
    short problem = -1;
    int _auto = 21; //set this to skip asking for a problem
    if(!_auto)
    {
        cin >> problem;
    }    
    else
    {
        problem = _auto;
        cout << problem << endl;
    }
    int output = 0;
    switch(problem)
    {
        case 2:
            for(int i = 1, j = 1, c = i; i < 4e6 ;c = i, i += j, j = c)
            {
                if(i%2==0)
                {
                    output += i;
                }
            }
            break;
        case 21:
            output = problem21();
            break;
        default:
            cout << "Problem " << problem << " does not exist!" << endl;
            return 1;
    }
    cout << "Problem " << problem << ": " << output << endl;
    return 0;
}

int factor_sum(int n)
{
    int sum = 0;
    int factors[10001];
    int cache[10001];
    
    for(int i = 0; i != 10001; i++)
    {
        factors[i] = 1;
        cache[i] = -1;
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
    return sum;
}
int amicable(int n)
{
    int i = factor_sum(n);
    return n == i? false : (factor_sum(i) == n)? i : 0;
}
int problem21()
{
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
