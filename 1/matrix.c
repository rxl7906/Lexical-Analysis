/*
Author: Robin Li
File: matrix.c
Description:
- BuildEmptyMatrix: reads states, start, accept then builds and returns the matrix array
- displayMatrix: prints Matrix
*/
#include <stdio.h> // input and output operations
#include <stdlib.h> // atoi 
#include <string.h> // strtok
#include "matrix.h" // header file to matrix functions
#include "classes.h" // header file to character classes

// initialize for reading in tokens
char *ptr, buf[256];
char *token;
// initialize transition matrix
TransMatrix transMatrix;

// helper function to make new node
MatrixNode newNode(int nextState, char action) {
	MatrixNode node;
	node.nextState = nextState;
	node.action = action;
	return node;
}

// read and build empty transition matrix
MatrixNode** BuildEmptyMatrix(FILE *fp) {
	int states;
	int start;
	int accept;
	// get states, start, and accept and put in transMatrix
	for (int i = 0; i < 3; i++) {
		ptr = fgets( buf, 256, fp); // get the first line
		token = strtok(ptr, " "); // separate by spaces
		
		// skip the first word and move to the integer
		token = strtok(NULL, " ");
		if ( i == 0) { // first line is states
			states = atoi(token);
			transMatrix.states = states;
		}else if ( i == 1) { // second line is start
			start = atoi(token);
			transMatrix.start = start;
		}else if ( i == 2) { // third line is accept
			accept = atoi(token);
			transMatrix.accept = accept;
		}
	}
	// initialize array to hold matrix nodes
	MatrixNode **matrix_array = malloc(sizeof(MatrixNode*)*states);

	for (int i = 0; i < states; i++) {
		matrix_array[i] = malloc(sizeof(MatrixNode)*N_CC);

		// fill matrix with 99d
		for (int j = 0; j < N_CC; j++){ 
			matrix_array[i][j].nextState = 99;
			matrix_array[i][j].action = 'd';
		}
	}
	return matrix_array;
}

// print matrix
void displayMatrix(TransMatrix transMatrix){
	int nextState;
	char action;
	printf("Scanning using the following matrix:\n");
	printf("     0    1    2    3    4    5    6    7    8    9   10   11\n");
	for (int i = 0; i < transMatrix.states; i++) {
		// print left hand side of matrix
		if ( i < 10 ) {
			printf(" %d",i);
		} else {
			printf("%d",i);
		}
		// print matrix
		for (int j = 0; j < N_CC; j++) {
			/*
			if ( j < 10 ){
				printf("%d%c..",node.nextState,node.action);
			}
			*/
			nextState = transMatrix.matrix[i][j].nextState;
			action = transMatrix.matrix[i][j].action;
			if (nextState < 10) {
				printf("...%d%c",nextState,action);
			} else {
				printf("..%d%c",nextState,action);
			}	
		}
		printf("\n");
	}
}	

// Build Transition Matrix based on inputs
TransMatrix BuildMatrix (FILE *fp) {
	// build empty matrix
	transMatrix.matrix = BuildEmptyMatrix(fp);
	int row; // the current row
	int c; // character class causing transition, the column
	int col;
	int k; // state to which transition goes
	char x; // action to be taken when this transition occurs

	// loop through each line
	while ( (ptr = fgets(buf, 256, fp)) != NULL) {
		token = strtok(ptr, " "); // split into tokens using space
		// first thing on each line is number of the state
		// to which this line applies
		row = atoi(token); // token string to integer

		// sscanf gets charClass, next state, action
		while ( (token = strtok(NULL," ")) !=NULL ) {
			sscanf(token, "%d/%d%c", &c, &k, &x);
			// store nextState and action
			col = c;
			transMatrix.matrix[row][col].nextState = k;
			transMatrix.matrix[row][col].action = x;
		}	
	}
	return transMatrix;
}

