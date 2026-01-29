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

int isQueueEmpty() {
    return queueFront == queueRear;
}

int isQueueFull() {
    return (queueRear + 1) % MAX_QUEUE_SIZE == queueFront;
}

void addLexemeToQueue(const char *lexeme) {
    if (isQueueFull()) {
        printf("Queue is full, cannot add '%s'\n", lexeme);
        return;
    }
    strcpy(lexemeQueue[queueRear], lexeme);
    queueRear = (queueRear + 1) % MAX_QUEUE_SIZE;
}

char *removeLexemeFromQueue() {
    if (isQueueEmpty()) {
        printf("Queue is empty, nothing to remove\n");
        return NULL;
    }
    char *lexeme = lexemeQueue[queueFront];
    queueFront = (queueFront + 1) % MAX_QUEUE_SIZE;
    return lexeme;
}

// Match a lexeme to its corresponding token name
const char *identifyToken(const char *lexeme) {
    for (int i = 0; i < MAX_TOKENS; i++) {
        if (strcmp(lexemeList[i], lexeme) == 0) {
            return tokenList[i];
        }
    }
    if (isalpha(lexeme[0])) return "IDENT";
    if (isdigit(lexeme[0])) return "INT_LIT";
    return "UNKNOWN";
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *sourceFile = fopen(argv[1], "r");
    if (!sourceFile) {
        printf("Cannot open file: %s\n", argv[1]);
        return 2;
    }

    char buffer[MAX_LEXEME_LENGTH];
    int index = 0;
    int currentChar, nextChar;

    while ((currentChar = fgetc(sourceFile)) != EOF) {
        if (isspace(currentChar)) continue;

        // Build identifier
        if (isalpha(currentChar)) {
            buffer[index++] = currentChar;
            while ((nextChar = fgetc(sourceFile)) != EOF && (isalpha(nextChar) || isdigit(nextChar))) {
                buffer[index++] = nextChar;
            }
            buffer[index] = '\0';
            addLexemeToQueue(buffer);
            index = 0;
            if (nextChar != EOF) ungetc(nextChar, sourceFile);
        }
        // Build number literal
        else if (isdigit(currentChar)) {
            buffer[index++] = currentChar;
            while ((nextChar = fgetc(sourceFile)) != EOF && isdigit(nextChar)) {
                buffer[index++] = nextChar;
            }
            buffer[index] = '\0';
            addLexemeToQueue(buffer);
            index = 0;
            if (nextChar != EOF) ungetc(nextChar, sourceFile);
        }
        // Build operators and symbols
        else {
            buffer[index++] = currentChar;
            nextChar = fgetc(sourceFile);
            if (nextChar != EOF) {
                if ((currentChar == ':' && nextChar == '=') || (currentChar == '*' && nextChar == '*') ||
                    (currentChar == '<' && nextChar == '=') || (currentChar == '>' && nextChar == '=') ||
                    (currentChar == '<' && nextChar == '>') ||
                    (currentChar == '+' && nextChar == '+') || (currentChar == '-' && nextChar == '-')) {
                    buffer[index++] = nextChar;
                } else {
                    ungetc(nextChar, sourceFile);
                }
            }
            buffer[index] = '\0';
            addLexemeToQueue(buffer);
            index = 0;
        }
    }
    fclose(sourceFile);

    printf("Jacob Wallace :: R11822561\n");

    while (!isQueueEmpty()) {
        char *lexeme = removeLexemeFromQueue();
        const char *token = identifyToken(lexeme);
        printf("%-12s %s\n", lexeme, token);
    }

    return 0;
}