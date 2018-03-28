/*
// Problem:
// https://www.codewars.com/kata/5813d19765d81c592200001a/train/c

// Useful stuff about Ints:
// https://stackoverflow.com/questions/3068397/finding-the-length-of-an-integer-in-c
// https://stackoverflow.com/questions/17144997/gets-last-digit-of-a-number

// Useful stuff about Strings:
// https://stackoverflow.com/questions/1496313/returning-c-string-from-a-function
// https://www.quora.com/How-can-I-pass-a-string-as-an-argument-to-a-function-and-return-a-string-in-C
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int dontGiveMeFive(int start, int end);
int cr_assert_eq(int result, int answer);

int main() {
    // Unit Testing
    dontGiveMeFive(2,14);
    printf("\n");

    // Test Cases
    // printf("Test #1: ");
    // cr_assert_eq(dontGiveMeFive(1,4), 3) ? printf("Correct!\n") : printf("Incorrect\n");

    return 0;
}

int dontGiveMeFive(int start, int end) {
    int result = 0;
    int startLen = floor(log10(abs(start))) - 1;
    int endLen = floor(log10(abs(end))) - 1;

    printf("startLen: %d, endLen: %d", startLen, endLen);

    result =  end - start;

    return result;
}

int cr_assert_eq(int result, int answer) {
    if (result == answer) {
        return 1;
    } else {
        return 0;
    }
}