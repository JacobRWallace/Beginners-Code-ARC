
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TRIES 6
#define MAX_WORD_LENGTH 20

// Function to choose a random word from a predefined list
const char* chooseRandomWord() {
    const char* wordList[] = {
        "programming",
        "computer",
        "hangman",
        "openai",
        "challenge"
    };

    int numWords = sizeof(wordList) / sizeof(wordList[0]);
    int randomIndex = rand() % numWords;

    return wordList[randomIndex];
}

// Function to initialize the game
void initialize(char* wordToGuess, char* currentGuess) {
    const char* selectedWord = chooseRandomWord();
    strcpy(wordToGuess, selectedWord);

    int wordLength = strlen(wordToGuess);
    for (int i = 0; i < wordLength; i++) {
        currentGuess[i] = '_';
    }
    currentGuess[wordLength] = '\0';
}

// Function to display the current state of the game
void displayState(char* currentGuess, int triesLeft) {
    printf("Current word: %s\n", currentGuess);
    printf("Tries left: %d\n", triesLeft);
}

// Function to check if the guessed letter is in the word
int checkGuess(char* wordToGuess, char* currentGuess, char guess) {
    int wordLength = strlen(wordToGuess);
    int found = 0;

    for (int i = 0; i < wordLength; i++) {
        if (wordToGuess[i] == guess) {
            currentGuess[i] = guess;
            found = 1;
        }
    }

    return found;
}

int main() {
    srand(time(NULL));
    char wordToGuess[MAX_WORD_LENGTH];
    char currentGuess[MAX_WORD_LENGTH];
    char guess;
    int triesLeft = MAX_TRIES;

    initialize(wordToGuess, currentGuess);

    printf("Welcome to Hangman!\n");

    while (1) {
        displayState(currentGuess, triesLeft);

        if (triesLeft == 0) {
            printf("You lose! The word was: %s\n", wordToGuess);
            break;
        }

        printf("Enter a letter guess: ");
        scanf(" %c", &guess); // Leading space to consume any whitespace characters

        if (checkGuess(wordToGuess, currentGuess, guess)) {
            printf("Correct guess!\n");
        } else {
            printf("Incorrect guess!\n");
            triesLeft--;
        }

        // Check if the player has guessed the entire word
        if (strcmp(wordToGuess, currentGuess) == 0) {
            printf("Congratulations! You've guessed the word: %s\n", wordToGuess);
            break;
        }
    }

    return 0;
}
