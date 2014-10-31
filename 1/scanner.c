/*
Author: Robin Li
File: scanner.c
Description:
- classification: takes in character from stdin and returns the character
class
- scanner: takes in the transition matrix and returns EOF to stop scanning
*/
#include <stdio.h> // printf, getchar
#include <stdlib.h> // free, malloc, realloc
#include "classes.h" // header file to macro constants
#include "matrix.h" // header file to matrix definitions
#define NONASCII 128 

// using ASCII values, classify its character class
int classification(char c){
	// whitespace characters: space, tab
	if ( c == 32 || c == 9) {
		return CC_WS;
	}
	// whitespace character: newline
	else if ( c == 10) {
		return CC_NEWLINE;
	}
	// alphabetic (A-Z, a-z) and underscore
	else if ( (c >=65 && c <= 90) || (c == 95) || (c >=97 && c <=122)) {
		return CC_ALPHA;
	}
	// digit character 0
	else if ( c == 48) {
		return CC_DIG_0;
	}
	// digit characters 1-7
	else if ( c>=49 && c <= 55){
		return CC_DIG_1_7;
	} 
	// digit character 8, 9
	else if ( c == 56|| c == 57){
		return CC_DIG_8_9;	
	}
	// division operator
	else if ( c == 47){
		return CC_CHAR_SLASH;
	}
	// multiplicative operator
	else if ( c == 42){
		return CC_CHAR_STAR;
	}
	// other arithmetic operators: +, -, %
	else if ( c == 43 || c == 45 || c == 37){
		return CC_ARITH_OP;
	}
	// either EOF on input or any non-ASCII
	else if ( c == EOF){
		// EOF on input
		if(ferror(stdin)==0) {
			return CC_EOF;
		}
		// any non-ASCII character
		else{
			return CC_ERROR;
		}
	}
	// any other ASCII character
	else {
		return CC_OTHER;
	}
}

// processing characters from standard input
int Scanner(TransMatrix transMatrix) {	
	char c;
	int charClass;
	int startState = transMatrix.start;
	int acceptState = transMatrix.accept;
	int currentState = startState; // current node when looping
	char *buffer = malloc(2); // buffer to store
	int count = 1;
	MatrixNode node;

	// loop until see classifer of accept state or 99
	while ( currentState != acceptState && currentState != 99){
		//MatrixNode node;
		c = getchar(); // read chars one at a time
		printf("%d ", currentState); // print each state
		charClass = classification(c); // classify each c
		// access matrix node
		node = transMatrix.matrix[currentState][charClass];

		// everytime see an s, allocate space, save it to the buffer
		if (node.action == 's') {
			count +=1;
			buffer = realloc(buffer,count + 1);
			// store buffer and charClass to buffer
			sprintf(buffer,"%s%c",buffer,c);
		}
		currentState = node.nextState;
	}
	// print last element
	printf("%d ", currentState);
	
	// if the current state is in the accept or EOF
	if (currentState == acceptState && charClass == CC_EOF){
		printf("EOF\n");
		free(buffer);
		return EOF;
	} else if (currentState == acceptState) {
		printf("recognized '%s'\n", buffer);
		free(buffer);
		return 0;
	} else {
		printf("rejected\n");
		while (( c=getchar()) != ' ') {}
		free(buffer);
		return 0;
	}
}
