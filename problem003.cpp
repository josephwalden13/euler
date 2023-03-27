#include <iostream>
#include "primes.h"

using namespace std;

int main() {
    vector<int> primes = getPrimes(100000);
    long long number = 600851475143;
    std::reverse(primes.begin(), primes.end());
    for (const auto &item: primes) {
        if (number % item == 0) {
            cout << item << endl;
            break;
        }
    }
}
