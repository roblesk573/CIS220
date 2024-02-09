/ Kevin Robles
// C PA 1

#include <stdio.h>

int main() {
    double fahrenheit, celsius, kelvin;

    // Prompting the user to enter the Fahrenheit temperature
    printf("Enter the Fahrenheit temperature you wish to convert: ");
    scanf("%lf", &fahrenheit);

    // Converting Fahrenheit to Celsius
    celsius = (fahrenheit - 32.0) * 5.0 / 9.0;

    // Converting Celsius to Kelvin
    kelvin = celsius + 273.15;

    // Displaying the converted temperatures
    printf("The Celsius temperature is %.2lf.\n", celsius);
    printf("The Kelvin temperature is %.2lf.\n", kelvin);

    return 0;
}