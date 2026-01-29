/*
=============================================================================
Title    : front.c
Description : This program works with the lexical analyzer for simple 
              arithmetic and conditional expressions, supporting tokens.
Author   : Jacob Wallace (R#11822561)
Date     : 11/22/2024
Version  : 1.0
Usage    : Compile and run program with parser using the makefile.
C Version: C11
=============================================================================
*/

#include <stdio.h>
#include <ctype.h>
#include "front.h"
#include "parser.h"

//global variables
int currentToken;
int currentLine = 1;
char currentLexeme[100];
char currentChar;

//local variables
static int charType;
static int lexemeLength;
static FILE *inputFile;

//this function adds the current character to the lexeme
static void addCharacter() {
    if (lexemeLength <= 98) {
        currentLexeme[lexemeLength++] = currentChar;
        currentLexeme[lexemeLength] = 0;  //null terminate the lexeme
    } else {
        printf("error - lexeme is too long\n");
    }
}

//this function reads the next character from the input file
static void getNextCharacter() {
    if ((currentChar = getc(inputFile)) != EOF) {
        if (currentChar == '\n') {
            currentLine++;
        }
        if (isalpha(currentChar))
            charType = LETTER;
        else if (isdigit(currentChar))
            charType = DIGIT;
        else
            charType = UNKNOWN;
    } else {
        charType = EOF;
    }
}

//this function skips whitespace characters
static void skipWhitespace() {
    while (isspace(currentChar)) getNextCharacter();
}

//this function determines the type of token based on the current character
static int lookupToken(char character) {
    switch (character) {
        case '=':
            addCharacter();
            currentChar = getc(inputFile);  //peek ahead
            if (currentChar == '=') {
                addCharacter();
                currentToken = EQUAL_OP;
            } else {
                ungetc(currentChar, inputFile);  //put back if not '='
                currentToken = ASSIGN_OP;
            }
            break;
        case '<':
            addCharacter();
            currentChar = getc(inputFile);
            if (currentChar == '=') {
                addCharacter();
                currentToken = LEQUAL_OP;
            } else {
                ungetc(currentChar, inputFile);
                currentToken = LESSER_OP;
            }
            break;
        case '>':
            addCharacter();
            currentChar = getc(inputFile);
            if (currentChar == '=') {
                addCharacter();
                currentToken = GEQUAL_OP;
            } else {
                ungetc(currentChar, inputFile);
                currentToken = GREATER_OP;
            }
            break;
        case '!':
            addCharacter();
            currentChar = getc(inputFile);
            if (currentChar == '=') {
                addCharacter();
                currentToken = NEQUAL_OP;
            } else {
                ungetc(currentChar, inputFile);
                currentToken = BOOL_NOT;
            }
            break;
        case '+':
            addCharacter();
            currentToken = ADD_OP;
            break;
        case '-':
            addCharacter();
            currentToken = SUB_OP;
            break;
        case '*':
            addCharacter();
            currentToken = MULT_OP;
            break;
        case '/':
            addCharacter();
            currentToken = DIV_OP;
            break;
        case '%':
            addCharacter();
            currentToken = MOD_OP;
            break;
        case '&':
            addCharacter();
            currentChar = getc(inputFile);
            if (currentChar == '&') {
                addCharacter();
                currentToken = BOOL_AND;
            } else {
                ungetc(currentChar, inputFile);
                currentToken = UNKNOWN;
            }
            break;
        case '|':
            addCharacter();
            currentChar = getc(inputFile);
            if (currentChar == '|') {
                addCharacter();
                currentToken = BOOL_OR;
            } else {
                ungetc(currentChar, inputFile);
                currentToken = UNKNOWN;
            }
            break;
        case '{':
            addCharacter();
            currentToken = OPEN_CURL;
            break;
        case '}':
            addCharacter();
            currentToken = CLOSE_CURL;
            break;
        case '(':
            addCharacter();
            currentToken = OPEN_PAREN;
            break;
        case ')':
            addCharacter();
            currentToken = CLOSE_PAREN;
            break;
        case ';':
            addCharacter();
            currentToken = SEMICOLON;
            break;
        default:
            addCharacter();
            currentToken = UNKNOWN;
            break;
    }
    return currentToken;
}

//this function analyzes the input file and generates tokens
int getNextToken() {
    lexemeLength = 0;
    skipWhitespace();

    switch (charType) {
        case LETTER:  //parse identifiers and keywords
            addCharacter();
            getNextCharacter();
            while (charType == LETTER || charType == DIGIT) {
                addCharacter();
                getNextCharacter();
            }
            if (strcmp(currentLexeme, "input") == 0) {
                currentToken = KEY_IN;
            } else if (strcmp(currentLexeme, "output") == 0) {
                currentToken = KEY_OUT;
            } else if (strcmp(currentLexeme, "if") == 0) {
                currentToken = KEY_IF;
            } else if (strcmp(currentLexeme, "else") == 0) {
                currentToken = KEY_ELSE;
            } else {
                currentToken = IDENT;  //default to identifier
            }
            break;

        case DIGIT:  //parse integer literals
            addCharacter();
            getNextCharacter();
            while (charType == DIGIT) {
                addCharacter();
                getNextCharacter();
            }
            currentToken = INT_LIT;
            break;

        case UNKNOWN:  //parse operators and special symbols
            lookupToken(currentChar);
            getNextCharacter();
            break;

        case EOF:  //end of file
            currentToken = EOF;
            strcpy(currentLexeme, "EOF");
            break;

        default:
            printf("error - unknown character class\n");
            currentToken = UNKNOWN;
            break;
    }

    printf("next token is: %d, next lexeme is %s\n", currentToken, currentLexeme);
    return currentToken;
}

//main driver function
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("error - no input file provided\n");
        return 2;
    } else if ((inputFile = fopen(argv[1], "r")) == NULL) {
        printf("error - cannot open %s\n", argv[1]);
        return 3;
    } else {
        printf("Cooke Parser :: R11822561\n");
        getNextCharacter();
        getNextToken();  //initialize first token
        startParsing();  //parse the file
        return 0;
    }
}