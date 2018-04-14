#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

#define MinSize 3
#define MaxSize 64 // defines macros


void draw_field(const char field[], int size);
int add_cross(char field[], int size, int position);
int is_solved(const char field[], int size);

char board; 
int win = 0;


void main(){

	int inputSize = 0;
	char userInput[MaxSize]; // gets char of max board 

	while(inputSize == 0){ // keeps looping until a valid answer is given 
		printf("Enter the size of field : \n");
		fgets(userInput, MaxSize, stdin); // gets userinput 

		if(strlen(userInput) < 2 || strlen(userInput) > 3){
			printf("Invalid Input\n");    // checks if userinput of char is greater than boardsize
			continue;
		}

		if(sscanf(userInput, "%d" , &inputSize) != 1){ // checks if the boardsize is a single digit
			inputSize = 0;
			printf("Invalid Input\n");
			continue;
		}

		if(inputSize < MinSize || inputSize > MaxSize){ // checks if userinput is within the boardsize range
			inputSize = 0;
			printf("Invalid board size!\n");
			continue;
		}

	}

	char boardSize[inputSize];
	for(int i = 0; i < inputSize; i++){
		boardSize[i] = ' '; // initialises board to ' ' 
	}


	draw_field(boardSize,inputSize);   


	while(win == 0){ // win boolean condition 

		int position = 0;

		while(position == 0){
			printf("Enter Position A : \n");
			fgets(userInput, MaxSize, stdin);

			if(strlen(userInput) < 2 || strlen(userInput) > 3){
				printf("Invalid Input\n");   
				continue;
			}

			if(sscanf(userInput, "%d" , &position) != 1){
				position = 0;
				printf("Invalid Input\n");
				continue;
			}

			if(position < 1 || position > inputSize){ // checks if the position is within board range input 
				position = 0;
				printf("Invalid board size!\n");
				continue;
			}

		}


		add_cross(boardSize,inputSize,position); // checks if the move is valid 

		win = is_solved(boardSize,inputSize);
		if(win == 1){
			printf("Player A won!\n");
			break;
		}

		int position2 = 0;

		while(position2 == 0){
			printf("Enter Position B : \n");
			fgets(userInput, MaxSize, stdin);

			if(strlen(userInput) < 2 || strlen(userInput) > 3){
				printf("Invalid Input\n");   
				continue;
			}

			if(sscanf(userInput, "%d" , &position2) != 1){
				position2 = 0;
				printf("Invalid Input\n");
				continue;
			}

			if(position2 < 1 || position2 > inputSize){
				position2 = 0;
				printf("Invalid board size!\n");
				continue;
			}

		}

		add_cross(boardSize,inputSize,position2); // checks if valid cross move 
		void validMove(char field[], int add_cross, int size);
		win = is_solved(boardSize,inputSize); // checks win condition 
		if(win == 1){
			printf("Player B won!\n");
			break;
		}

	}

}


void draw_field(const char field[], int size){


	for(int i = 0; i < size; i++){
		printf("+-"); // draws top half 
	}
	printf("+\n");

	int x = 0;
	void validMove(char field[], int add_cross, int size);
	while(x < size){
		printf("|%c", field[x++]); // draws chars 

	}
	printf("|\n");

	for(int i = 0; i < size; i++){ // draws bot half 
		printf("+-");
	}
	printf("+\n");

	for(int i = 0; i < size; i++){
		if(i <= 9){
			printf(" %d", i+1);
		}else{
			printf("%d", i+1);
		}

	}
	printf("\n");
}

int add_cross(char field[], int size, int position){

	if(field[position-1] == ' ' && position <= size && position > 0){ // checks if valid and draws cross. 
		field[position-1] = 'X';
		draw_field(field,size);
	}
	else if(field[position-1] == 'X' && position <= size){ // shows error 
		printf("X is already there!\n");
	}else{
		printf("Wrong position!\n");
	}
}

int is_solved(const char field[], int size){

	for(int i = 0; i < size; i++){
		if(field[i] == 'X' && field[i+1] == 'X' && field[i-1] == 'X'){ // checks win condition
			return 1;
		}
	}
	return 0;
}

