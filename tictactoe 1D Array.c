#include <stdio.h>


void draw_field(const char field[], int size);
int add_cross(const char field[], int size, int position);
int is_solved(const char field[], int size);

char board; 

void main(){

    int inputSize;
    int win = 0;

    printf("Enter the size of field : \n");
    scanf("%d", &inputSize);
    char boardSize[inputSize];


 draw_field(boardSize, inputSize);   
}

void draw_field(const char field[], int size){
     
    
    for(int i = 0; i < size; i++){
        printf("+-");
    }
    printf("+\n");
    
    for(int i = 0; i < size; field[i++])
        printf("|%c");
        
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

int add_cross(const char field[], int size, int position){
    
}

int is_solved(const char field[], int size){
    
}
