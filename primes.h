//
// Created by Joseph Walden on 23/03/2023.
//

#include "vector"
#include "set"

using namespace std;

#ifndef EULER_PRIMES_H
#define EULER_PRIMES_H

vector<int> getPrimes(int n);
vector<int> getPrimeFactors(vector<int> *primes, int number);
void expandFactors(set<int> *factors, vector<int> *primes, int n);
int LCM(int a, int b);
bool *getSieve(int max);

#endif //EULER_PRIMES_H
