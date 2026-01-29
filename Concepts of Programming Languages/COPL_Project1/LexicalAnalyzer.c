#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_QUEUE_SIZE 500  // define queue capacity to hold lexemes
#define MAX_LEXEME_LENGTH 100  // define capacity for length of lexemes
#define MAX_TOKENS 26  // defines how many unique tokens we have to identify

// arrays of lexeme for our tokens
const char *lexemes[MAX_TOKENS] = {
    "=", "<", ">", "==", "!=", "<=", ">=", "(", ")", "+", "-", "*", "/",
    "%", "&&", "||", "!", ";", "input", "output", "if", "else", "{", "}", "V", "N"
};

// tokens array that matches the lexemes array
const char *tokens[MAX_TOKENS] = {
    "ASSIGN_OP", "LESSER_OP", "GREATER_OP", "EQUAL_OP", "NEQUAL_OP", "LEQUAL_OP",
    "GEQUAL_OP", "OPEN_PAREN", "CLOSE_PAREN", "ADD_OP", "SUB_OP", "MULT_OP",
    "DIV_OP", "MOD_OP", "BOOL_AND", "BOOL_OR", "BOOL_NOT", "SEMICOLON",
    "KEY_IN", "KEY_OUT", "KEY_IF", "KEY_ELSE", "OPEN_CURL", "CLOSE_CURL",
    "IDENT", "INT_LIT"
};

// queue for storing lexemes
char queue[MAX_QUEUE_SIZE][MAX_LEXEME_LENGTH];
int front = 0, rear = 0;  // track start and end of queue

// function to check if the queue is empty
int isQueueEmpty() {
    return front == rear;
}

// function to check if the queue is full
int isQueueFull() {
    return (rear + 1) % MAX_QUEUE_SIZE == front;
}

// function to add a new lexeme to the queue
void enqueue(const char *lexeme) {
    if (isQueueFull()) {
        printf("Queue is full, cannot enqueue '%s'\n", lexeme);
        return;
    }
    strcpy(queue[rear], lexeme);
    rear = (rear + 1) % MAX_QUEUE_SIZE;
}

// function to remove a lexeme from the queue
char *dequeue() {
    if (isQueueEmpty()) {
        printf("Queue is empty, cannot dequeue\n");
        return NULL;
    }
    char *lexeme = queue[front];
    front = (front + 1) % MAX_QUEUE_SIZE;
    return lexeme;
}

// function to search the lexemes array and find the correct token
const char *matchToken(const char *lexeme) {
    for (int i = 0; i < MAX_TOKENS; i++) {
        if (strcmp(lexemes[i], lexeme) == 0) {
            return tokens[i];
        }
    }
    // if lexeme is an alphabetic string, it’s an identifier
    if (isalpha(lexeme[0])) {
        return "IDENT";
    }
    // if lexeme contains numbers, it's an integer literal
    if (isdigit(lexeme[0])) {
        return "INT_LIT";
    }
    return "UNKNOWN";
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        printf("Error opening file: %s\n", argv[1]);
        return 2;
    }

    char buffer[MAX_LEXEME_LENGTH];
    int bufferIndex = 0;  // track index in buffer
    int ch, nextCh;

    // read file and add lexemes to the queue
    while ((ch = fgetc(file)) != EOF) {
        if (isspace(ch)) {
            continue;  // skip whitespace characters
        }

        // handle alphabetic characters or identifiers
        if (isalpha(ch)) {
            buffer[bufferIndex++] = ch;
            while ((nextCh = fgetc(file)) != EOF && (isalpha(nextCh) || isdigit(nextCh))) {
                buffer[bufferIndex++] = nextCh;
            }
            buffer[bufferIndex] = '\0';
            enqueue(buffer);  // add identifier to queue
            bufferIndex = 0;

            // return last read character if not part of the identifier
            if (nextCh != EOF) {
                ungetc(nextCh, file);
            }
        }
        // handle numeric characters for integer literals
        else if (isdigit(ch)) {
            buffer[bufferIndex++] = ch;
            while ((nextCh = fgetc(file)) != EOF && isdigit(nextCh)) {
                buffer[bufferIndex++] = nextCh;
            }
            buffer[bufferIndex] = '\0';
            enqueue(buffer);  // add number to the queue
            bufferIndex = 0;

            // return last read character if not part of the number
            if (nextCh != EOF) {
                ungetc(nextCh, file);
            }
        }
        // handle other characters and special operators
        else {
            buffer[bufferIndex++] = ch;
            nextCh = fgetc(file);
            if (nextCh != EOF) {
                // check for multi-character operators like ==, !=, <=, >=, &&, ||
                if ((ch == '=' && nextCh == '=') || (ch == '!' && nextCh == '=') ||
                    (ch == '<' && nextCh == '=') || (ch == '>' && nextCh == '=') ||
                    (ch == '&' && nextCh == '&') || (ch == '|' && nextCh == '|')) {
                    buffer[bufferIndex++] = nextCh;
                } else {
                    // return last character if not part of a double operator
                    ungetc(nextCh, file);
                }
            }
            buffer[bufferIndex] = '\0';
            enqueue(buffer);  // add operator or symbol to queue
            bufferIndex = 0;
        }
    }
    fclose(file);

    // output student info
    printf("Jacob Wallace :: R11822561\n");

    // process queue and find matching tokens for each lexeme
    while (!isQueueEmpty()) {
        char *lexeme = dequeue();
        const char *token = matchToken(lexeme);
        printf("%-12s %s\n", lexeme, token);  // print lexeme and matching token
    }

    return 0;
}
