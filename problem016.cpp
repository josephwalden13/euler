#include <iostream>
#include "bignumber.h"

using namespace std;
int main()
{
    bignumber t = bignumber("1");
    for(int i = 0; i != 1000; i++)
    {
        t.int_multiply(2);
    }
    int length = t.value().length();
    int sum = 0;
    for (int i = 0; i != length; i++)
    {
        sum += (t.value()[i] - '0');
    }
    cout << sum << endl;
}
