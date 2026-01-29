/*
=============================================================================
Title    : parser.c
Description : This program implements a recursive-descent parser for simple 
              arithmetic and conditional expressions.
Author   : Jacob Wallace (R#11822561)
Date     : 11/22/2024
Version  : 1.0
Usage    : Compile and run this program with the associated lexical analyzer
           using the provided Makefile.
C Version: C11
=============================================================================
*/

#include <stdio.h>
#include "parser.h"
#include "front.h"

//this function reports syntax errors and terminates the program
static void handleError() {
    if (currentChar == '\n') currentLine--;
    printf("error encountered on line %d: the next lexeme was %s and the next token was %d\n", currentLine, currentLexeme, currentToken);
    exit(1);
}

//this function initiates the parsing process
void startParsing() {
    printf("enter <parse>\n");
    while (currentToken != EOF) {
        processStatement();  //parse each statement
    }
    printf("exit <parse>\n");
}

//this function parses arithmetic and logical expressions
void evaluateExpression() {
    printf("enter <expr>\n");
    evaluateTerm();
    while (currentToken == ADD_OP || currentToken == SUB_OP || currentToken == EQUAL_OP || currentToken == NEQUAL_OP || currentToken == BOOL_AND || currentToken == BOOL_OR || currentToken == LESSER_OP || currentToken == GREATER_OP) {
        getNextToken();  //consume operator
        evaluateTerm();  //parse the next term
    }
    printf("exit <expr>\n");
}

//this function parses terms in expressions
void evaluateTerm() {
    printf("enter <term>\n");
    evaluateFactor();
    while (currentToken == MULT_OP || currentToken == DIV_OP || currentToken == MOD_OP) {
        getNextToken();    //consume operator
        evaluateFactor();  //parse the next factor
    }
    printf("exit <term>\n");
}

//this function parses factors in terms
void evaluateFactor() {
    printf("enter <factor>\n");
    if (currentToken == IDENT || currentToken == INT_LIT) {
        getNextToken();  //consume valid factor
    } else if (currentToken == OPEN_PAREN) {
        getNextToken();  //consume '('
        evaluateExpression();  //parse nested expression
        if (currentToken == CLOSE_PAREN) {
            getNextToken();  //consume ')'
        } else {
            handleError();  //missing closing parenthesis
        }
    } else {
        handleError();  //invalid token
    }
    printf("exit <factor>\n");
}

//this function parses statements based on their type
void processStatement() {
    printf("enter <stmt>\n");
    switch (currentToken) {
        case IDENT:  //handle assignment
            getNextToken();  //consume IDENT
            if (currentToken == ASSIGN_OP) {
                getNextToken();  //consume '='
                evaluateExpression();  //parse expression
                if (currentToken == SEMICOLON) {
                    getNextToken();  //consume ';'
                    printf("valid assignment statement.\n");
                } else {
                    handleError();  //missing semicolon
                }
            } else {
                handleError();  //missing '='
            }
            break;

        case KEY_IN:  //handle input(V);
            getNextToken();  //consume 'input'
            if (currentToken == OPEN_PAREN) {
                getNextToken();  //consume '('
                if (currentToken == IDENT) {
                    getNextToken();  //consume IDENT
                    if (currentToken == CLOSE_PAREN) {
                        getNextToken();  //consume ')'
                        if (currentToken == SEMICOLON) {
                            getNextToken();  //consume ';'
                            printf("valid input statement.\n");
                        } else {
                            handleError();  //missing semicolon
                        }
                    } else {
                        handleError();  //missing ')'
                    }
                } else {
                    handleError();  //missing identifier
                }
            } else {
                handleError();  //missing '('
            }
            break;

        case KEY_OUT:  //handle output(E);
            getNextToken();  //consume 'output'
            if (currentToken == OPEN_PAREN) {
                getNextToken();  //consume '('
                evaluateExpression();  //parse expression
                if (currentToken == CLOSE_PAREN) {
                    getNextToken();  //consume ')'
                    if (currentToken == SEMICOLON) {
                        getNextToken();  //consume ';'
                        printf("valid output statement.\n");
                    } else {
                        handleError();  //missing semicolon
                    }
                } else {
                    handleError();  //missing ')'
                }
            } else {
                handleError();  //missing '('
            }
            break;

        case KEY_IF:  //handle if (C) { S } [else { S }]
            getNextToken();  //consume 'if'
            if (currentToken == OPEN_PAREN) {
                getNextToken();  //consume '('
                evaluateCondition();  //parse condition
                if (currentToken == CLOSE_PAREN) {
                    getNextToken();  //consume ')'
                    if (currentToken == OPEN_CURL) {
                        getNextToken();  //consume '{'
                        processStatementList();  //parse block
                        if (currentToken == CLOSE_CURL) {
                            getNextToken();  //consume '}'
                            if (currentToken == KEY_ELSE) {
                                getNextToken();  //consume 'else'
                                if (currentToken == OPEN_CURL) {
                                    getNextToken();  //consume '{'
                                    processStatementList();  //parse block
                                    if (currentToken == CLOSE_CURL) {
                                        getNextToken();  //consume '}'
                                        printf("valid if-else statement.\n");
                                    } else {
                                        handleError();  //missing '}'
                                    }
                                } else {
                                    handleError();  //missing '{' after else
                                }
                            }
                        } else {
                            handleError();  //missing '}'
                        }
                    } else {
                        handleError();  //missing '{'
                    }
                } else {
                    handleError();  //missing ')'
                }
            } else {
                handleError();  //missing '('
            }
            break;

        default:
            handleError();  //unknown statement
    }
    printf("exit <stmt>\n");
}

//this function processes a list of statements
void processStatementList() {
    printf("enter <stmtList>\n");
    while (currentToken != CLOSE_CURL && currentToken != EOF) {
        processStatement();
    }
    printf("exit <stmtList>\n");
}

//this function parses conditions in if-statements
void evaluateCondition() {
    printf("enter <condition>\n");
    evaluateExpression();
    while (currentToken == LESSER_OP || currentToken == GREATER_OP || currentToken == EQUAL_OP || currentToken == NEQUAL_OP || currentToken == LEQUAL_OP || currentToken == GEQUAL_OP || currentToken == BOOL_AND || currentToken == BOOL_OR) {
        getNextToken();  //consume operator
        evaluateExpression();
    }
    printf("exit <condition>\n");
}