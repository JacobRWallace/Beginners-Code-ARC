#include <stdio.h>

int main() {
    int a = 10;
    float b = 5.66;

    // Binary operators
    float addition = a + b;
    int subtraction = a - b;
    int multiplication = a * b;
    int division = a / b;
    int x=1,y=2,z=3;
    int answer=x+y*-z*z+a;
    printf("answer= %d\n",answer);
    //int remainder = a % b;

    // Unary operators
    int unary_plus = +a;  // This doesn't change the value of 'a'.
    int unary_minus = -b; // Negate the value of 'b'.

    // Display the results
    printf("a + b = %0.3f\n", addition);
    printf("a - b = %d\n", subtraction);
    printf("a * b = %d\n", multiplication);
    printf("a / b = %d\n", division);
  //  printf("a %% b = %d\n", remainder); // Note: Use %% to print a '%' character.
    printf("+a = %d\n", unary_plus);
    printf("-b = %d\n", unary_minus);

    return 0;
}