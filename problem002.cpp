#include <iostream>
using namespace std;
int main()
{
    int sum = 0;
    for(int i = 1, j = 1, c = i; i < 4e6 ;c = i, i += j, j = c)
    {
        if(i%2==0)
        {
            sum += i;
        }
    }
    cout << sum << endl;
}
