// Kevin Robles
// Chpt2 PA

#include <stdio.h>

// Calculate base raised to the power of exponent
int power(int base, int exponent) {
    // Base case: when exponent is 1, return base
    if (exponent == 1) {
        return base;
    }
    // Calculate base raised to the power of (exponent - 1)
    // and multiply it by base
    return base * power(base, exponent - 1);
}

int main() {
    int base, exponent, result;

    // Enter the base
    printf("Enter base: ");
    scanf("%d", &base);

    // Enter the exponent
    printf("Enter exponent: ");
    scanf("%d", &exponent);

    // Calculating the result using the power function
    result = power(base, exponent);

    // Displaying the result
    printf("Value is %d\n", result);

    return 0;
}