#include <iostream>
#include "primes.h"

using namespace std;

int main() {
    long sum = 0;
    vector<int> primes = getPrimes(2e6);
    for ( int &item: primes) {
        sum += item;
    }
    cout << sum << endl;
}
