#include <iostream>
#include "bignumber.h"

using namespace std;
int main()
{
    bignumber t = bignumber("1001");
    cout << t.value() << endl;
    t.subtract(bignumber("100"));
    t.multiply(bignumber(2));
    cout << t.value() << endl;
}
