#include <iostream>
using namespace std;
long getPaths(int size, int x = 0, int y = 0)
{
    long paths = 0;
    if (x < size)
    {
        paths += getPaths(size, x + 1, y);
    }
    if (y < size)
    {
        paths += getPaths(size, x, y + 1);
    }
    if (x==y && x == size)
    {
        paths++;
    }
    return paths;
}
int main()
{
    long count = getPaths(20);
    
    cout << count << endl;
}
