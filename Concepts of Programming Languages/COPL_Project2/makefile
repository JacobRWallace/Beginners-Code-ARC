# ===============================================================================
# Title    : makefile
# Description : This makefile compiles and links the lexical analyzer and 
#               parser programs.
# Author   : Jacob Wallace (R#11822561)
# Date     : 11/22/2024
# Version  : 1.0
# Usage    : Use `make` to compile the project, `make clean` to remove object 
#            files and executables.
# ===============================================================================

all: parser

parser: front.o parser.o
	$(CC) -Wall front.o parser.o -o cooke_parser
	$(CC) -Wall front.o parser.o -o parser	

.c.o:
	$(CC) -Wall -c $<


test: cooke_parser
	./cooke_parser test_file.dc
	./parser

clean:
	$(RM) parser.o front.o parser

# LEAVE COMMENTS HE SAID HE WILL DEDUCT 3/10/25