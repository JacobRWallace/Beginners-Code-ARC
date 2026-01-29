#include <stdio.h>
#include <stdlib.h>

// Function prototype
void dispense(int total, int *hundreds, int *fifty, int *twenty, int *ten);

int main(){

    int userInput;
    int twenty = 0, ten = 0, fifty = 0, hundreds = 0;

    printf("ATM Bill Dispenser\n\nEnter an amount that is a multiple of 10 to be dispensed\n");

    do {
        printf("Enter desired amount: ");
        scanf(" %d", &userInput);

        //Check that it is a multiple of 10 and non-negative
        if (userInput % 10 != 0 || userInput < 0) {
            printf("Invalid value, please try again.\n");
        }
    } while (userInput % 10 != 0 || userInput < 0);

    if (userInput == 0) {
        printf ("Cannot dispense $0.00\n");
        return 0;
    }
    //Call the dispense function to calculate the bills
    dispense(Fill arguments);

    printf("Dispense successful. In");
    printf("Number of bills dispensed for $%d:\nHundreds: %d\nFifty: %d\nTwenty: %d\nTen: %d\n",
           userInput, hundreds, fifty, twenty, ten);
    return 0;
