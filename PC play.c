#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MinSize 3
#define MaxSize 64 // define marcos 

void draw(int size, const char field[][size]);
int add_cross(int size, char field[][size], const char player, int x, int y);
int is_solved(int size, const char field[][size]);
void make_turn(int size, char field[][size]);

int win = 0;
char PC;
int positionXPC= 0;
int positionYPC = 0;

void main(){
	int inputSize = 0;
	char userInput[MaxSize];

	while(inputSize == 0){// keeps looping until a valid answer is given 
		printf("Enter the size of field : \n");
		fgets(userInput, MaxSize, stdin);// gets userinput 

		if(strlen(userInput) < 2 || strlen(userInput) > 3){// checks if userinput of char is greater than boardsize
			printf("Invalid Input\n");   
			continue;
		}

		if(sscanf(userInput, "%d" , &inputSize) != 1){// checks if the boardsize is a single digit
			inputSize = 0;
			printf("Invalid Input\n");
			continue;
		}

		if(inputSize < MinSize || inputSize > MaxSize){// checks if userinput is within the boardsize range
			inputSize = 0;
			printf("Invalid board size!\n");
			continue;
		}

	}


	char boardSize[inputSize][inputSize];
	for(int i = 0; i < inputSize; i++){
		for(int x = 0; x < inputSize; x++){ // initalises 2d board to ' ' 
			boardSize[i][x] = ' ';
		}
	}

	draw(inputSize,boardSize); // makes sure board size is valid 


	while(win == 0){// win boolean condition 
		int positionX = 0;
		int positionY = 0;

		while(positionX == 0 ){ //checks for invalid input for row position 
			printf("Enter Position A row : \n");
			fgets(userInput, MaxSize, stdin);

			if(strlen(userInput) < 2 || strlen(userInput) > 3){
				printf("Invalid Input\n");   
				continue;
			}

			if(sscanf(userInput, "%d", &positionX ) != 1){
				positionX = 0;

				printf("Invalid Input\n");
				continue;
			}

			if(positionX < 1 || positionX > inputSize){// checks if the position is within board range input 
				positionX = 0;
				printf("Invalid board size!\n");
				continue;
			}

		}

		while(positionY == 0 ){//checks for invalid input for column position 
			printf("Enter Position A column : \n");
			fgets(userInput, MaxSize, stdin);

			if(strlen(userInput) < 2 || strlen(userInput) > 3){
				printf("Invalid Input\n");   
				continue;
			}

			if(sscanf(userInput, "%d", &positionY ) != 1){
				positionY = 0;

				printf("Invalid Input\n");
				continue;
			}

			if(positionY < 1 || positionY > inputSize){
				positionY = 0;
				printf("Invalid board size!\n");
				continue;
			}

		}

		add_cross(inputSize,boardSize,'A',positionX,positionY); // checks valid move 
		win = is_solved(inputSize, boardSize); // ends game if solved 
		if(win == 1){
			printf("Player A won!\n");
			break;
		}

		printf("Enter Position PC: \n");   
		make_turn(inputSize, boardSize); // gets turn for pc and checks it 



		win = is_solved(inputSize,boardSize);
		if(win == 1){
			printf("PC won!\n");
			break;
		}

	}

}



void draw(int size, const char field[][size]){

	int temp = size;
	while (temp != 0){

		printf(" ");
		printf(" ");
		for(int i = 1; i <= size; i++){
			printf("+-");
		}
		printf("+\n"); // draws top 

		if(temp <= 9){
			printf(" %d",temp); // gets number side 
		}else{
			printf("%d",temp); 
		}

		for (int i = 0; i < size; i++){
			printf("|%c",field[i][temp-1]); // prints charc 
		}
		printf("|\n");
		temp--; 
	}
	printf(" "); // add spacing to make it look equal 
	printf(" ");
	for(int i = 1; i <= size; i++){
		printf("+-");
	}

	printf("+\n"); // prints bottom half 
	printf(" ");
	printf(" ");

	for(int i = 0; i < size; i++){
		if(i <= 9){
			printf(" %d", i + 1); // prints numbers 
		}else{
			printf("%d", i + 1);
		}
	}
	printf(" \n");

}

int add_cross(int size, char field[][size], const char player, int x, int y){


	if(field[x-1][y-1] == ' ' && x <= size && y <=size && x > 0 && y >0){ // checks valid conditions 
		if(player == 'A'){
			field[x-1][y-1] = 'X';
		}else{
			field[x-1][y-1] = 'O';
		}
		draw(size,field);
	}else if((field[x-1][y-1] == 'X'||field[x-1][y-1] == 'O')&& x <= size && y <=size){
		if(player == 'A') printf("Position already taken!\n");
		else{
			make_turn(size, field); // if pc position taken already make it take another turn 
		}
	}
	else{
		printf("Wrong position!\n");

	} 
}

int is_solved(int size, const char field[][size]){
	//fix for O aswell
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			if((field[i][j] == 'X' && field[i+1][j] == 'X' && field[i-1][j] == 'X') ||  // checks cross 
					(field[i][j] == 'X' && field[i][j+1] == 'X' && field[i][j-1]) ||  // checks up / down 
					(field[i][j] == 'X' && field[i+1][j+1] == 'X' && field[i-1][j-1] == 'X') ||  // checks diag
					(field[i][j] == 'X'  && field[i-1][j+1] == 'X'&& field[i+1][j-1] == 'X')) // checks diag 
			{
				return 1;
			}
			else if((field[i][j] == 'O' && field[i+1][j] == 'O' && field[i-1][j] == 'O') || 
					(field[i][j] == 'O' && field[i][j+1] == 'O'  && field[i][j-1]) || 
					(field[i][j] == 'O' && field[i+1][j+1] == 'O' && field[i-1][j-1] == 'O') || 
					(field[i][j] == 'O' && field[i-1][j+1] == 'O' && field[i+1][j-1] == 'O'))
			{
				return 1;	
			}

		}
	}
	return 0;
}


void make_turn(int size, char field[][size]){
	positionXPC = (rand()%size) +1;
	positionYPC = (rand()%size) + 1;
	add_cross(size, field,'B',positionXPC, positionYPC); // gets rand input for x and y 

}

