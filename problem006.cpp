#include <iostream>
using namespace std;
int main()
{
    int sum = 0;
    int square_sum = 0;
    for(int i = 1; i <= 100; i++)
    {
        sum += i;
        square_sum += i * i;
    }
    int difference = (sum * sum) - square_sum;
    cout << difference << endl;
    return 0;
}



