//
// Created by Joseph Walden on 24/03/2023.
//

#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;

class bignumber { 
    int n_digits;
    short* digits;
    public: 
    bignumber(int a) {
        n_digits = floor(log10(a)) + 1;
        digits = new short[n_digits];
        for(int i = n_digits - 1; i >= 0; i--) { 
            digits[i] = a % 10;
            a /= 10;
        }
    }

    bignumber(int a, int n) { 
        n_digits = n;
        digits = new short[n_digits];
        for(int i = n_digits - 1; i >= 0; i--) { 
            digits[i] = a % 10;
            a /= 10;
        }
    }

    void extend(int n) { 
        n_digits += n;
        short *d = new short[n];
        for(int i = 0; i != n; i++) { 
            d[i] = 0;
        }
        for(int j = 0; j != n_digits - n; j++) { 
            d[j + n] = digits[j];
        }
        delete digits;
        digits = d;
    }

    bignumber operator+(const bignumber& other) const {
        int n = max(n_digits, other.n_digits);
        bignumber sum = bignumber(0, n);
        for(int i = 1; i <= n_digits; i++) { 
            sum.digits[n - i] = digits[n_digits - i];
        }
        for(int j = 1; j <= other.n_digits; j++) { 
            sum.digits[n - j] += other.digits[other.n_digits - j];
        }
        
        int i = n_digits - 1;
        while (i >= 0) { 
            if(sum.digits[i] >= 10) { 
                if(i == 0) { 
                    sum.extend(1);
                }
                else { 
                    sum.digits[i - 1] += sum.digits[i] / 10;
                    sum.digits[i] %= 10;
                    i--;
                }
            }
            else { 
                i--;
            }
        }
        return sum;
    }

    friend ostream& operator<< (ostream& os, bignumber num) { 
        for(int i = 0; i < num.n_digits; i++) { 
             os << num.digits[i];
        }
        return os;
    }
};

int main() {
    int index;
    // bignumber a = 1;
    // cout << "Number: " << a << endl;
    // bignumber b = 1;
    // for(index = 0; index != 100; index++) { 
    //     bignumber c = a + b;
    //     cout << index << ": " << a << endl;
    //     a = b;
    //     b = c;
    // }
    bignumber a = 8, b = 13;
    cout << a + b << endl;
    return 0;
}