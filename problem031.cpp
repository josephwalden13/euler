#include <iostream>

using namespace std;

const int denominations[] = {200, 100, 50, 20, 10, 5, 2, 1};
const int denomination_length = 8;

int get_ways(int a, int start = 0) { 
    int b = 0;
    int i = start;
    for(; i < denomination_length; i++) { 
        if(a > denominations[i]) { 
            b += get_ways(a - denominations[i], i);
        }
        else if (a == denominations[i]) { 
            b++;
        }
    }
    return b;
}

int main() {
    int money = 200;
    cout << "Ways: " << get_ways(money) << endl;
}
