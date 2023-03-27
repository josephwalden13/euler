#include <iostream>
#include "primes.h"

using namespace std;

int main() {
    vector<int> primes = getPrimes(1000000);
    cout << "Prime 10001: " << primes[10001] << endl;
}
