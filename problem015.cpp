#include <iostream>
unsigned long long cache[21][21];
using namespace std;
unsigned long long getPaths(int size, int x = 0, int y = 0)
{
    unsigned long long paths = 0;
    if (cache[x][y] > 0)
    {
        return cache[x][y];
    }
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
    if (paths > 0)
    {
        cache[x][y] = paths;
    }
    return paths;
}
int main()
{
    for (int i = 0; i != 21; i++)
    {
        for(int j = 0; j != 21; j++)
        {
            cache[i][j] = 0;
        }
    }
    cout << "Calculating paths through 20x20 lattice: " << flush;
    unsigned long long count = getPaths(20, 0, 0);
    cout << count << endl;
}
