#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_QUEUE_SIZE 500
#define MAX_LEXEME_LENGTH 100
#define MAX_TOKENS 27

// List of valid language symbols or keywords
const char *lexemeList[MAX_TOKENS] = {
    ":=", "+", "-", "*", "/", "**",
    "<", ">", "=", "<>",
    "<=", ">=", "++", "--",
    "(", ")", ":", ";",
    "read", "print", "if", "else", "begin", "end",
    "V", "N", "?"
};

// Corresponding token names for the lexemes
const char *tokenList[MAX_TOKENS] = {
    "ASSIGN_OP", "ADD_OP", "SUB_OP", "MULT_OP", "DIV_OP", "POW_OP",
    "LESSER_OP", "GREATER_OP", "EQUAL_OP", "NEQUAL_OP",
    "LEQUAL_OP", "GEQUAL_OP", "INC_OP", "DEC_OP",
    "LEFT_PAREN", "RIGHT_PAREN", "COLON", "SEMICOLON",
    "KEY_READ", "KEY_PRINT", "KEY_IF", "KEY_ELSE", "KEY_BEGIN", "KEY_END",
    "IDENT", "INT_LIT", "UNKNOWN"
};

// Queue structure to temporarily store lexemes
char lexemeQueue[MAX_QUEUE_SIZE][MAX_LEXEME_LENGTH];
int queueFront = 0, queueRear = 0;


int main(int argc, char *argv[]) {

    FILE *sourceFile = fopen(argv[1], "r");

    char temp[MAX_LEXEME_LENGTH];
    int tempIndex = 0;
    int currentChar, nextChar;

    // loop through file by character
    while ((currentChar = fgetc(sourceFile)) != EOF) {
        if(!(isalpha(currentChar)||isdigit(currentChar))) continue;

        // if it starts with a character
        if(isalpha(currentChar)) {
            temp[tempIndex] = currentChar;
            tempIndex++;

            while((nextChar = fgetc(sourceFile)) != EOF && (isalpha(nextChar)||isdigit(nextChar))){
                temp[tempIndex] = nextChar;
                tempIndex++;
            }

            strcpy(lexemeQueue[queueRear], temp);
            queueRear = (queueRear + 1) % MAX_QUEUE_SIZE;
        }

        // starts with a number
        else if(isdigit(currentChar)) {

        }

    }

    fclose(sourceFile);

    /*
    for(int i = 0; i<MAX_QUEUE_SIZE; i++){
        for(int j = 0; j<MAX_LEXEME_LENGTH; j++){
            printf("queue: %s\n", lexemeQueue);
        }
    }
    */

    printf("Jacob Wallace :: R11822561\n");
    return 0;
}