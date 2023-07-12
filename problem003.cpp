#include <iostream>
#include "primes.h"

using namespace std;

int main() {
    vector<int> primes = getPrimes(100000);
    long long number = 600851475143;
    std::reverse(primes.begin(), primes.end());
    for(int i = 0; i != primes.size(); i++) {
        if (number % primes[i] == 0) {
            cout << primes[i] << endl;
            break;
        }
    }
}
