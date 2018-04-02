#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void draw_field(char field[][], int size);
int add_cross(char field[][], int size, int position);
int is_solved(char field[][], int size);
void validMove(char field[][], int add_cross, int size);

char board; 

void main(){
    
    int inputSize;
    int win = 0;
    int position = 0;
    
    
    

    printf("Enter the size of field : \n");
    scanf("%d", &inputSize);
    char boardSize[inputSize];
    for(int i = 0; i < inputSize; i++){
        for(int x = 0; x < inputSize; x++){
            
        boardSize[i][x] = ' ';
        }
    }


    draw_field(boardSize,inputSize);   
    
    
    while(win == 0){
        
     printf("Enter Position Player A: ");   
     scanf("%d",&position);
     
     validMove(boardSize,add_cross(boardSize,inputSize,position),inputSize);
     
     win = is_solved(boardSize,inputSize);
     if(win == 1){
      printf("Player A won!\n");
      break;
     }
     
     printf("Enter Position Player B: ");   
     scanf("%d",&position);
     
     validMove(boardSize,add_cross(boardSize,inputSize,position),inputSize);
     
     win = is_solved(boardSize,inputSize);
     if(win == 1){
      printf("Player B won!\n");
      break;
     }
        
    }
     
}

void draw_field(char field[][], int size){
     
    for(int j = 0; j < size; j++){
        for(int i = 0; i < size; i++){
        printf("+-");
        }
        printf("+\n");
    
        int x = 0;
    
        while(x < size){
            printf("|%c", field[x++]);
        
        }
        printf("|\n");
    
        for(int i = 0; i < size; i++){
            printf("+-");
        }
        printf("+\n");
    
    }
    
    
    
    for(int i = 0; i < size; i++){
        printf(" %d", i+1);
    }
     printf("\n");
}

int add_cross(char field[][], int size, int position){
    
    if(field[position-1] == ' ' && position <= size && position > 0){
        field[position-1] = 'X';
        return 1;
    }
    else if(field[position-1] == 'X' && position <= size){
        return 0;
    }
    return -1;
}
 
int is_solved(char field[][], int size){
    //fix for O aswell
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
        if(((field[i][j] == 'X' || field[i][j] == 'O')&& field[i+1][j] == 'X' && field[i-1][j] == 'X') || 
            ((field[i][j] == 'X' || field[i][j] == 'O')&& field[i][j+1] == 'X' && field[i][j-1]) || 
            ((field[i][j] == 'X' || field[i][j] == 'O')&& field[i+1][j+1] == 'X' && field[i-1][j-1] == 'X') || 
            (((field[i][j] == 'X' || field[i][j] == 'O') && field[i-1][j+1] == 'X'&& field[i+1][j-1] == 'X'))
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

void validMove(char field[][], int add_cross, int size){
        if(add_cross ==1){
            draw_field(field,size);
        }
        else if(add_cross == 0){
            printf("X is already there!\n");
        }
        else if(add_cross == -1){
            printf("Wrong position!\n");
        }
}
