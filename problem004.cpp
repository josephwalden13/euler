#include <iostream>
#include <cstdio>
#include <string>
#include <cstdlib>

using namespace std;

int main() {
    int largest = 0;
    for (int i = 900; i != 999; i++) {
        for (int j = 900; j != 999; j++) {
            int number = i * j;
            string s = to_string(number);
            string rev = to_string(number);
            std::reverse(rev.begin(), rev.end());
            if(s == rev && number > largest) {
                largest = number;
            }
        }
    }
    cout << "Largest: " << largest << endl;
}
