#include <iostream>
#include <cstdlib>
unsigned long long problem15_cache[51][51];
int recursions = 0;
using namespace std;
unsigned long long getPaths(int size, int x = 0, int y = 0)
{
    unsigned long long paths = 0;
    if (problem15_cache[x][y] > 0)
    {
        return problem15_cache[x][y];
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
        problem15_cache[x][y] = paths;
    }
    recursions++;
    return paths;
}
int main()
{
    for (int i = 0; i != 51; i++)
    {
        for(int j = 0; j != 51; j++)
        {
            problem15_cache[i][j] = 0;
        }
    }
    int grid = 20;
    if (grid > 50)
    {
        cout << "Please enter a number under 50" << endl;
        exit(1);
    }
    cout << "Calculating paths through " << grid << 'x' << grid << " lattice: " << flush;
    unsigned long long count = getPaths(grid, 0, 0);
    cout << count << endl;
    cout << "Total recursions: " << recursions << endl;
}
