/*
Author: Robin Li
File: matrix.h
Description
- make new type struct: MatrixNode - node
- make new type struct: TransMatrix - 2d array matrix
- BuildMatrix function - input file, return TransMatrix
- displayMatrix funciton - input TransMatrix, print the matrix
*/
#ifndef _MATRIX_H_
#define _MATRIX_H_

// MatrixNode data structure
typedef struct MatrixNode {
	int nextState;
	char action;
} MatrixNode;

// Transition matrix data structure
typedef struct TransMatrix {
	MatrixNode** matrix;
	int states;
	int start;
	int accept;
} TransMatrix;

// build matrix function
TransMatrix BuildMatrix(FILE *fp);

// print matrix function
void displayMatrix(TransMatrix transmatrix);

#endif
