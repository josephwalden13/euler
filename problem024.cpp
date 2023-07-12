//
// Created by Joseph Walden on 23/03/2023.
//

/*
 * A permutation is an ordered arrangement of objects.
 * For example, 3124 is one possible permutation of the digits 1, 2, 3 and 4.
 * If all of the permutations are listed numerically or alphabetically, we call it lexicographic order.
 * The lexicographic permutations of 0, 1 and 2 are:
012   021   102   120   201   210
What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?
 */

#include "stdio.h"
#include "string.h"
#include "stdlib.h"
// #include "omp.h"

int count = 0;

char *removeChar(char *number, char remove) {
    int len = strlen(number);
    char *output = new char[len - 1];
    int i, j;
    for (i = 0, j = 0; i != len; i++) {
        if (number[i] != remove) {
            output[j] = number[i];
            j++;
        }
    }
    output[len] = '\0';
    return output;
}

char **getPermutations(char *number, char *previous) {
    int len = strlen(number);
    if (len == 0) {
        count += 1;
        if (count == 1e6) {
            printf("%s\n", previous);
        }
    }
    for (int i = 0; i != len; i++) {
        char *copy = (char *) malloc(len * sizeof(char));
        strcpy(copy, number);

        char *subset = removeChar(copy, number[i]);
        int prevLen = strlen(previous);
        char *prevCopy = new char[prevLen + 1];
        strcpy(prevCopy, previous);
        prevCopy[prevLen] = number[i];
        prevCopy[prevLen + 1] = '\0';
        getPermutations(subset, prevCopy);
    }
    return NULL;
}

int main() {
    char number[11] = {"0123456789"};
    getPermutations(number, new char[0]);
    return 0;
}