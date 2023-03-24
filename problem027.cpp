//
// Created by Joseph Walden on 23/03/2023.
//

#include <iostream>
#include "primes.h"

using namespace std;

int formula(int n, int a, int b) {
    return pow(n, 2) + a * n + b;
}

int main() {
    bool* primes = getSieve(1e7);

    int max = 0, a = 0, b = 0;
    int i, j;
    for (i = -999; i < 1000; i++) {
        for (j = -1000; j <= 1000; j++) {
            int k = 0;
            int fun = (int)pow(k, 2) + (i * k) + j;
            while (primes[fun]) {
                k++;
                fun = (int)pow(k, 2) + (i * k) + j;
            }
            if (k > max) {
                max = k;
                a = i;
                b = j;
            }
        }
    }

    cout << "A: " << a << endl;
    cout << "B: " << b << endl;
    cout << "Answer: " << a * b << endl;
}