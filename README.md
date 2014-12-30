Project: Lexical Analysis 
Author: Robin Li
------------------------------------------------------------------------
BACKGROUND:
Language processing programs (such as compilers, interpreters, and 
assemblers) examine the source code being processed. First it is broken
up into component pieces (lexical analysis). Then verified that those 
pieces form legal statements (syntax analysis). Then generate an 
equivalent version of the program that can be executed by the compiler
(code generation). The Lexical Analysis Scanner part of processing
tokens can be described as a Finite-State Machine. The scanner reads
the input character by character, determining what type of element
each represents and converts the information into a token to be handled
by the syntax analyzer (parser) to examine input elements and verify their legality. 
------------------------------------------------------------------------
OVERVIEW:
This program implements a Lexical Analysis Scanner to read a subset of the
C language: identifiers, decimal integers, octal integers, block-style comments, and basic arithmetic operators. The scanner is implemented using a transition matrix. 
------------------------------------------------------------------------
FILES:
-classes.h - define names for character classes
-header.mak - for make file
-input.1 - test case
-matrix.c - BuildEmptyMatrix and displayMatrix funciton
-matrix.h - MatrixNode and TransMatrix type struct defined. BuildMatrix
function, display matrix function
-myoutput - example output
-output.1 - example output
-scanner.c - classification and scanner function
-scanner.h - scanner function
-tm.1 - example matrix
-tokenize.c - Verifies command-line arguments, then reads indicated file
 and builds the transition matrix. Processes characters from standard input. 