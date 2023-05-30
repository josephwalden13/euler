#include <iostream>
#include <cmath>
#include <omp.h>

using namespace std;

const int p = 5;
const int m = 1e6;

int main() {
    int total = 0;

    #pragma omp parallel for
    for(int i = 2; i < m; i++) { 
        int num = i;
        int sum = 0;
        while(num >= 10) { 
            int d = num % 10;
            num /= 10;
            int po = pow(d, 5);
            if (po > i) { 
                break;
            }
            sum += po;
            if(sum > i) { 
                break;
            }
        }
        if(sum < i) { 
            sum += pow(num, 5);
            if(sum == i) { 
                cout << i << endl;
                total += i;
            }
        }
    }
    cout << "Total: " << total;
}
