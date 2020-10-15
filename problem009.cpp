#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
    for (int i = 1; i != 1000; i++) 
    {
        for (int j = 1; j != 1000; j++)
        {
            for (int k = 1; k != 1000; k++)
            {
                if (i*i + j*j == k*k && i+j+k==1000)
                {   
                    cout << i*j*k << endl;
                    exit(0);
                }
            }
        }    
    }
}
