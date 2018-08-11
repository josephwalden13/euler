#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
int main()
{
    int largest = 0;
    for (int i = 900; i != 999; i++)
    {
        for(int j = 900; j != 999; j++)
        {
            char buffer [6];
            sprintf(buffer, "%d", (i*j));
            char reverse [6];
            for(int i = 5; i >= 0; i--)
            {
                reverse[5-i] = buffer[i];
            }
            if (strcmp(reverse, buffer) == 0)
            {
                if (atoi(buffer) > largest)
                {
                    largest = atoi(buffer);
                }
            }
        }
    }
    cout << largest << endl; 
}
