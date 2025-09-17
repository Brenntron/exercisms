#include "armstrong_numbers.h"

bool is_armstrong_number(int candidate)
{
    if (candidate < 0) {
        return false; // Negative numbers are not Armstrong numbers
    }

    int original = candidate;
    int sum = 0;
    int digits = 0;

    // Count the number of digits
    while (candidate > 0) {
        digits++;
        candidate /= 10;
    }

    candidate = original;

    // Calculate the sum of each digit raised to the power of the number of digits
    while (candidate > 0) {
        int digit = candidate % 10;
        int power = 1;
        for (int i = 0; i < digits; i++) {
            power *= digit;
        }
        sum += power;
        candidate /= 10;
    }

    return sum == original;
}
