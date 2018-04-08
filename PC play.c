#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
    void draw(int size, const char field[][size]);
    int add_cross(int size, char field[][size], const char player, int x, int y);
    int is_solved(int size, const char field[][size]);
    void make_turn(int size, char field[][size]);

    int inputSize;
    int win = 0;
    int positionX = 0;
    int positionY = 0; 
	char PC;
    
    
    void main(){
        printf("Enter the size of field: ");
        int check = scanf("%d", &inputSize);
        if(check!=1){
            printf("That is not a number! Please enter an integer\n");
            return;
        }
        
        char boardSize[inputSize][inputSize];
        for(int i = 0; i < inputSize; i++){
            for(int x = 0; x < inputSize; x++){
                boardSize[i][x] = ' ';
            }
        }
        if(inputSize >= 3 && inputSize <= 64){
            draw(inputSize,boardSize);
        
        }else{
            printf("That is a invalid boardSize! Please enter an integer\n");
            return;
        }

        while(win == 0){

            printf("Enter Position Player A: ");  
            scanf("%d %d",&positionX,&positionY);


            add_cross(inputSize,boardSize,'A',positionX,positionY);
            win = is_solved(inputSize, boardSize);
            if(win == 1){
                printf("Player A won!\n");
                break;
            }

            printf("Enter Position PC: %d %d\n", positionX, positionY);   
            make_turn(inputSize, boardSize);
  

            
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
            for(int i = 1; i <= size; i++){
              printf("+-");
            }


            printf("+\n");
           
            
            printf("%d",temp);

            for (int i = 0; i < size; i++){
                printf("|%c",field[i][temp-1]);
            }
            printf("|\n");
            temp--;
        }
          printf(" ");
        
          for(int i = 1; i <= size; i++){
            printf("+-");
            }
      
          printf("+\n");
          printf(" ");
        
          for(int i = 0; i < size; i++){
            printf(" %d", i + 1);
        }
          printf(" \n");
    


    }

    int add_cross(int size, char field[][size], const char player, int x, int y){


        if(field[x-1][y-1] == ' ' && x <= size && y <=size && x > 0 && y >0){
            if(player == 'A'){
                field[x-1][y-1] = 'X';
            }else{
                field[x-1][y-1] = 'O';
            }
              draw(size,field);
        }else if((field[x-1][y-1] == 'X'||field[x-1][y-1] == 'O')&& x <= size && y <=size){
            if(player == 'A') printf("Position already taken!\n");
            else{
            make_turn(inputSize, field);
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
                if((field[i][j] == 'X' && field[i+1][j] == 'X' && field[i-1][j] == 'X') || 
                (field[i][j] == 'X' && field[i][j+1] == 'X' && field[i][j-1]) || 
                (field[i][j] == 'X' && field[i+1][j+1] == 'X' && field[i-1][j-1] == 'X') || 
                (field[i][j] == 'X'  && field[i-1][j+1] == 'X'&& field[i+1][j-1] == 'X'))
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
    positionX = (rand()%size) +1;
    positionY = (rand()%size) + 1;
    add_cross(inputSize, field,'B',positionX, positionY);

}

