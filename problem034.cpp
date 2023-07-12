#include <iostream>

using namespace std;

const int m = 1e6;

int factorial(int n) { 
    if(n == 0) {
	    return 1;
    }
    else if(n == 1) {
        return 1;
    }
    else if(n == 2) {
        return 2;
    }
    else if(n == 3) {
        return 6;
    }
    else if(n == 4) {
        return 24;
    }
    else if(n == 5) {
        return 120;
    }
    else if(n == 6) {
        return 720;
    }
    else if(n == 7) {
        return 5040;
    }
    else if(n == 8) {
        return 40320;
    }
    else if(n == 9) {
        return 362880;
    }
    return 1;
}

int main() {
    int total = 0;
    #pragma omp parallel for
    for(int i = 11; i < m; i++) { 
        int num = i;
        int sum = 0;
        while(num >= 10) { 
            int d = num % 10;
            num /= 10;
            int po = factorial(d);
            if (po > i) { 
                break;
            }
            sum += po;
            if(sum > i) { 
                break;
            }
        }
        if(sum < i) { 
            sum += factorial(num);
            if(sum == i) { 
                cout << i << endl;
                total += i;
            }
        }
    }
    cout << "Total: " << total;
}
