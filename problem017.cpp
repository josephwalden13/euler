//
// Created by Joseph Walden on 06/03/2023.
//

#define UPPER 1000

#include <iostream>
#include <cmath>
#include <sys/time.h>

using namespace std;

int length(const char *string) {
    if (string == nullptr) {
        return 0;
    }
    int i;
    for (i = 0; ::strcmp(&string[i], "\0") != 0; i++);
    return i;
}

const char *units[10] = {nullptr, "one", "two", "three",
                         "four", "five", "six", "seven",
                         "eight", "nine"};
const char *teens[10] = {"ten", "eleven", "twelve", "thirteen",
                         "fourteen", "fifteen", "sixteen", "seventeen",
                         "eighteen", "nineteen"};
const char *tens[10] = {nullptr, nullptr, "twenty", "thirty",
                        "forty", "fifty", "sixty", "seventy",
                        "eighty", "ninety"};


#pragma clang diagnostic push
#pragma ide diagnostic ignored "misc-no-recursion"

const char *name_of_int(int i) {
    if (i < 10) {
        return units[i];
    } else if (i < 20) {
        return teens[i % 10];
    } else if (i < 100) {
        if (i % 10 == 0) {
            //tens
            return tens[i / 10];
        } else {
            //tens + units
            const char *ten = tens[(int) (floor(i / 10))];
            const char *unit = units[i % 10];
            int len_ten = length(ten), len_unit = length(unit);
            char *combined = new char[len_ten + len_unit + 1];
            int x, y;
            for (x = 0; x != len_ten; x++) {
                combined[x] = ten[x];
            }
            for (y = 0; y != len_unit; y++) {
                combined[x + y] = unit[y];
            }
            combined[x + y] = '\0';
            return combined;
        }
    } else if (i < 1000) {
        //tens + units
        const char *unit = units[(int) (floor(i / 100))];
        const char *str_hundred = "hundred";
        int len_unit = length(unit);
        char *hundred = new char[len_unit + 8];
        int j, k;
        for (j = 0; j != len_unit; j++) {
            hundred[j] = unit[j];
        }
        for (k = 0; k != length(str_hundred); k++) {
            hundred[j + k] = str_hundred[k];
        }
        hundred[j + k] = '\0';
        if (i % 100 == 0) {
            return hundred;
        }
        const char *remainder = name_of_int(i % 100);
        int len_hundred = length(hundred), len_remainder = length(remainder);
        char *combined = new char[len_hundred + 3 + len_remainder + 1];
        int x, y = 0, z = 0;
        for (x = 0; x != len_hundred; x++) {
            combined[x] = hundred[x];
        }
        if (len_remainder > 0) {
            for (; y != 3; y++) {
                combined[x + y] = "and"[y];
            }
            for (; z != len_remainder; z++) {
                combined[x + y + z] = remainder[z];
            }
        }
        combined[x + z + y] = '\0';
        return combined;
    } else if (i == 1000) return "onethousand";
    return nullptr_t();
}

#pragma clang diagnostic pop

int main() {
    int char_sum = 0;
    timeval start = {}, end = {};
    gettimeofday(&start, nullptr);
    for (int i = 1; i <= UPPER; i++) {
        char_sum += length(name_of_int(i));
    }
    gettimeofday(&end, nullptr);
    cout << char_sum << endl;
    cout << "Took " << (end.tv_sec - start.tv_sec) << " seconds" << endl;
    return 0;
}
