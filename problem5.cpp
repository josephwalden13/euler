#include <iostream>
using namespace std;
int main()
{
    for(long long i = 20;true; i += 20)
    {
        bool multiplies = true;
        for (int j = 20; j != 10; j--)
        {
            if (i % j != 0)
            {
                multiplies = false;
                break;
            }
        }
        if(multiplies)
        {
            cout << i << endl;
            break;
        }
    }
}
