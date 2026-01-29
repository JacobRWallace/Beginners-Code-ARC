#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
  
#define MAX_QUEUE_SIZE 500
#define MAX_LEXEME_LENGTH 100 
#define MAX_TOKENS 27 
 
const char *lexList[MAX_TOKENS] = {
    ":=", "+", "-", "*", "/", "**",
    "<", ">", "=", "<>",
    "<=", ">=", "++", "--",
    "(", ")", ":", ";",
    "read", "print", "if", "else", "begin", "end",
    "V", "N", "?"

};

const char *tokList[MAX_TOKENS] = {
    "ASSIGN_OP", "ADD_OP", "SUB_OP", "MULT_OP", "DIV_OP", "POW_OP",
    "LESSER_OP", "GREATER_OP", "EQUAL_OP", "NEQUAL_OP",
    "LEQUAL_OP", "GEQUAL_OP", "INC_OP", "DEC_OP",
    "LEFT_PAREN", "RIGHT_PAREN", "COLON", "SEMICOLON",
    "KEY_READ", "KEY_PRINT", "KEY_IF", "KEY_ELSE", "KEY_BEGIN", "KEY_END",
    "IDENT", "INT_LIT", "UNKNOWN" 
};
  
char lexQueue[MAX_QUEUE_SIZE][MAX_LEXEME_LENGTH];
int qFront = 0, qBack = 0;

void queueLex(char *lexeme) { 
    strcpy(lexQueue[qBack], lexeme);
    qBack = (qBack + 1) % MAX_QUEUE_SIZE;
}


int longOperatorCheck(char c1, char c2) {
    char temp[3] = {c1, c2, '\0'};

    for (int i = 0; i < MAX_TOKENS; i++) {
        if (strcmp(temp, lexList[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

const char* tokenize(char *lexeme) {
    for (int i = 0; i < MAX_TOKENS; i++) {
        if (strcmp(lexeme, lexList[i]) == 0){
            return tokList[i];
        }
    }

    if (isalpha(lexeme[0])) 
        return "IDENT";
    if (isdigit(lexeme[0])) 
        return "INT_LIT"; 

    return "UNKNOWN"; 
}

void genLexs() {
    while (qFront != qBack) { 
        char *lexeme = lexQueue[qFront];
        char *token = tokenize(lexeme);
        
        printf("%-10s %s\n", token, lexeme);
        qFront = (qFront + 1) % MAX_QUEUE_SIZE;
    }
}


int main(int argc, char *argv[]){
    FILE *file = fopen(argv[1], "r"); //read the file

    char temp[MAX_LEXEME_LENGTH]; 
    int tempIndex = 0; 
    int charCurrent, charNext;

    while ((charCurrent = fgetc(file)) != EOF) {
        if(!(isalpha(charCurrent)||isdigit(charCurrent))){ //if ch is whitespacec
            continue; //break loop
        }

        if(isalpha(charCurrent)) { //if ch is a alphabetical character
            //============================================================
            temp[tempIndex] = charCurrent; 
            tempIndex++; 
            //iterate rest of the term
            while((charNext = fgetc(file)) != EOF && (isalpha(charNext)||isdigit(charNext))){
                temp[tempIndex] = charNext; 
                tempIndex++; 
            }
            temp[tempIndex] = '\0';
            queueLex(temp);
            tempIndex = 0;

            if (charNext != EOF) {
                ungetc(charNext, file); }
            //============================================================


            /*
            strcpy(lexQueue[qBack], temp); 
            qBack = (qBack + 1) % MAX_QUEUE_SIZE;
            */
        }
        
        else if(isdigit(charCurrent)) { //if ch is a digit
            //============================================================
            temp[tempIndex] = charCurrent; 
            tempIndex++; 
            //iterate rest of the term
            while((charNext = fgetc(file)) != EOF && isdigit(charNext)){
                temp[tempIndex] = charNext; 
                tempIndex++; 
            }
            temp[tempIndex] = '\0';
            queueLex(temp);
            tempIndex = 0;

            if (charNext != EOF) {
                ungetc(charNext, file); }
            //============================================================
        }

        else{ //default if none
            temp[tempIndex] = charCurrent; 
            tempIndex++; 

            charNext = fgetc(file);

            if (charNext != EOF && (longOperatorCheck(charCurrent, charNext))) {
                temp[tempIndex++] = charNext;
            }
            else if(charNext != EOF){
                ungetc(charNext, file);
            }

            temp[tempIndex] = '\0';
            queueLex(temp);
            tempIndex = 0;
        }

    }

    fclose(file);

    /*
    for(int i = 0; i<MAX_QUEUE_SIZE; i++){
        for(int j = 0; j<MAX_LEXEME_LENGTH; j++){
            printf("queue: %s\n", lexQueue);
        }
    }
    */

    genLexs();
    printf("Jacob Wallace :: R11822561\n");
    return 0;
}