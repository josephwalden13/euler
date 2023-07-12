#include <iostream>
#include "primes.h"

using namespace std;

int main() {
    long sum = 0;
    vector<int> primes = getPrimes(2000000);
    for(int i = 0; i != primes.size(); i++) {
        sum += primes[i];
    }
    cout << sum << endl;
}
