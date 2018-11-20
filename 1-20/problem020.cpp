#include <iostream>
#include "bignumber.h"

using namespace std;
int main()
{
    bignumber t = bignumber("1");
    for(int i = 2; i != 101; i++)
    {
        t.int_multiply(i);
    }
    int length = t.value().length();
    int sum = 0;
    for (int i = 0; i != length; i++)
    {
        sum += (t.value()[i] - '0');
    }
    cout << sum << endl;
}
