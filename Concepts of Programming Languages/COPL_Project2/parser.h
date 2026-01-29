/*
=============================================================================
Title    : parser.h
Description : Header file for the recursive-descent parser in parser.c. Defines 
              function prototypes for parsing expressions and statements.
Author   : Jacob Wallace (R#11822561)
Date     : 11/22/2024
Version  : 1.0
Usage    : Include this header file in parser.c for access to function 
           declarations used for parsing.
Notes    : Ensure that this file is in the same directory as parser.c.
=============================================================================
*/

#ifndef PARSER_H
#define PARSER_H

void parse();
void expr();
void term();
void factor();
void stmt();
void stmtList();

#endif
