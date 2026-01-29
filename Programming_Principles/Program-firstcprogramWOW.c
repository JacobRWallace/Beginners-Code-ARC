/* Converts Fahrenheit to Celsius*/
#include<stdio.h>
#define FREEZING_POINT 32.00f
#define SCALING_FACTOR 5/9

int main(void) {
    float fahrenheit, celsius;

    // Read an input to fahrenheit
    printf("Give an input for fahrenheit temperature: ");
    scanf("%f", &fahrenheit);

    /* Converting Fahrenheit to Celsius*/
    celsius=(fahrenheit-FREEZING_POINT*SCALING_FACTOR);

    // Printing the Celsius equivalent
    printf("Celsius equivalent: %0.1f\n",celsius);
    return 0;
}








