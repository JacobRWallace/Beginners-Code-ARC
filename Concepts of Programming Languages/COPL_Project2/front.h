/*
=============================================================================
Title    : front.h
Description : Header file for the lexical analyzer in front.c. Defines token 
              codes, character classes, and external variables/functions used
              for tokenizing input.
Author   : Jacob Wallace (R#11822561)
Date     : 11/22/2024
Version  : 1.0
Usage    : Include this header file in front.c and parser.c for access to 
           token definitions and lexical functions.
Notes    : Ensure that this file is in the same directory as the source files.
=============================================================================
*/

#ifndef FRONT_H
#define FRONT_H

//character classes
#define LETTER 0
#define DIGIT 1
#define UNKNOWN 99

//token codes
#define INT_LIT 10
#define IDENT 11
#define ASSIGN_OP 20
#define LESSER_OP 21
#define GREATER_OP 22
#define EQUAL_OP 23
#define NEQUAL_OP 24
#define LEQUAL_OP 25
#define GEQUAL_OP 26
#define ADD_OP 27
#define SUB_OP 28
#define MULT_OP 29
#define DIV_OP 30
#define MOD_OP 31
#define BOOL_AND 32
#define BOOL_OR 33
#define BOOL_NOT 34
#define OPEN_CURL 35
#define CLOSE_CURL 36
#define OPEN_PAREN 37
#define CLOSE_PAREN 38
#define SEMICOLON 39
#define KEY_IN 40
#define KEY_OUT 41
#define KEY_IF 42
#define KEY_ELSE 43

//external variables for lexical analysis
extern int currentLine;
extern char currentLexeme[100];
extern char currentChar;
extern int currentToken;

//this function analyzes input and returns the next token
int getNextToken();

#endif