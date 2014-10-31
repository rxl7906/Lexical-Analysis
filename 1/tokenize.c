/* 
Author: Robin Li
Class: Mechanics of Programming CSCI-243
Project#1: Lexical Analysis
File: tokenize.c
Description: 
- verify command-line arguments (using main)
- read indicated file and build the transition matrix (using BuildMatrix)
- process characters from the standard input (using Scanner)
*/
#include <stdio.h> // input output operations
#include <stdlib.h> // exit 
#include "matrix.h" // header file to the matrix and scanner functions
#include "scanner.h"// header file to scanner functions

int main (int argc, char *argv[]) {
	if (argc != 2) {
		printf("usage: ./tokenize tm_file\n");
		exit(1);
	} else if (argc == 2) {
		FILE *fp;
		fp = fopen ( argv[1], "r");
		if ( fp == NULL ) {
			// something went wrong
			perror( argv[1] );
			exit( 1 );
		}
		// build matrix
		TransMatrix transMatrix = BuildMatrix(fp);
		// print matrix
		displayMatrix(transMatrix);
		/* process stdin and print state transitions from start
		to accepting state until end of file	
		*/
		while(Scanner(transMatrix) != EOF);
		//Scanner(transMatrix);
		// close the stream
		fclose(fp);
		}
	return 0;
}

