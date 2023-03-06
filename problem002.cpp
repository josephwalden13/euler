#include <iostream>
#include <sys/time.h>
using namespace std;
int main()
{
    struct timeval start = {}, end = {};
    gettimeofday(&start, nullptr);
    int sum = 0;
    for(int i = 1, j = 1, c = i; i < 4e6 ;c = i, i += j, j = c)
    {
        if(i % 2 == 0)
        {
            sum += i;
        }
    }
    gettimeofday(&end, nullptr);
    cout << sum << endl;
    cout << "Took " << (end.tv_sec - start.tv_sec) << " seconds" << endl;
}
