
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Seed the random number generator
    srand(time(NULL));

    int number_to_guess = rand() % 100 + 1;  // Generate a random number between 1 and 100
    int guess;
    int attempts = 0;

    printf("Welcome to the Guess the Number game!\n");
    printf("I'm thinking of a number between 1 and 100. Try to guess it.\n");

    while (1) {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        attempts++;

        if (guess < number_to_guess) {
            printf("Too low! Try again.\n");
        } else if (guess > number_to_guess) {
            printf("Too high! Try again.\n");
        } else {
            printf("Congratulations! You guessed the number (%d) in %d attempts!\n", number_to_guess, attempts);
            break;
        }
    }

    return 0;
}
