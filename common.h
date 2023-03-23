// common.h
//
#include "vector"

using namespace std;

#ifndef LZZ_common_h
#define LZZ_common_h
bool * getSieve (int max);
int primeCount (int max);
int * getPrimes (int max);
vector<int> getPrimes_vector(int n);
vector<int> getPrimeFactors(vector<int>* primes, int number);
std::vector<int> getPrimes();
#endif
