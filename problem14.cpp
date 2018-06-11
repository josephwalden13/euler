#include <iostream>
using namespace std;
int main()
{
    int n = 1004507;
    while(n != 1)
    {
        cout << n << endl;
        if (n&0x1)
        {
            n = (n << 1) + n + 1;
        }
        else
        {
            n = n >> 1;
        }
    }
    cout << 1 << endl;
}
