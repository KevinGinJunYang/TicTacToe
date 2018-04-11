#include <stdio.h>
#include <string.h>
#include <stdlib.h>



void draw_field(const char field[], int size);
int add_cross(char field[], int size, int position);
int is_solved(const char field[], int size);

char board; 
int inputSize;
int win = 0;
int position = 0;

void main(){
    
    

    printf("Enter the size of field : \n");
    int checkNumber = scanf("%d", &inputSize);
    if(checkNumber!=1){
       printf("That is not a number! Please enter an integer\n");
        return;
    }
    char boardSize[inputSize];
    for(int i = 0; i < inputSize; i++){
        boardSize[i] = ' ';
    }

    if(inputSize >= 3 && inputSize <= 64){

    draw_field(boardSize,inputSize);   
    
    }
    else{
        printf("That is a invalid boardSize! Please enter an integer\n");
     return;
    }
    
    while(win == 0){
        
     printf("Enter Position Player A: ");   
       int checkNumber = scanf("%d",&position);
        
    if(checkNumber!=1){
       printf("That is not a number! Please enter an integer\n");
        return;
    }
     
     validMove(boardSize,add_cross(boardSize,inputSize,position),inputSize);
      
     win = is_solved(boardSize,inputSize);
     if(win == 1){
      printf("Player A won!\n");
      break;
     }
     
     printf("Enter Position Player B: ");   
        int checkNumber2 = scanf("%d",&position); 
        
        if(checkNumber2!=1){
       printf("That is invalid! Please enter an integer\n");
        return;
    }
     
     validMove(boardSize,add_cross(boardSize,inputSize,position),inputSize);
     
     win = is_solved(boardSize,inputSize);
     if(win == 1){
      printf("Player B won!\n");
      break;
     }
        
    }
     
}


void draw_field(const char field[], int size){
     
    
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
    
    for(int i = 0; i < size; i++){
        printf(" %d", i+1);
      
    }
     printf("\n");
}

int add_cross(char field[], int size, int position){
    
    if(field[position-1] == ' ' && position <= size && position > 0){
        field[position-1] = 'X';
       draw_field(field,size);
    }
    else if(field[position-1] == 'X' && position <= size){
         printf("X is already there!\n");
    }else{
        
    printf("Wrong position!\n");
    }
}
 
int is_solved(const char field[], int size){
    
    for(int i = 0; i < size; i++){
        if(field[i] == 'X' && field[i+1] == 'X' && field[i-1] == 'X'){
            return 1;
        }
    }
    return 0;
}

