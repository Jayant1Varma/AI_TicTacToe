
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 3

typedef struct prediction {

    int abscissa;       //(x)
    int ordinate;       //(y)

} prediction;

// Used for Computer vs Human feature : 

prediction* predictWin (char matrix[SIZE][SIZE], char mark){       // if no win is predictable, return NULL     

    prediction* prd = (prediction*) malloc(sizeof(prediction));

   for(int i = 0 ; i < SIZE; i++){                      //row checking

        if(matrix[i][0] == mark && matrix[i][1] == mark && matrix[i][2] != 'X' && matrix[i][2] != 'O'){
             prd -> abscissa = i;
             prd -> ordinate = 2;
             return prd;
        }

        if(matrix[i][0] == mark && matrix[i][2] == mark && matrix[i][1] != 'X' && matrix[i][1] != 'O'){
             prd -> abscissa = i;
             prd -> ordinate = 1;
             return prd;
         }
        
        if(matrix[i][2] == mark && matrix[i][1] == mark && matrix[i][0] != 'X' && matrix[i][0] != 'O'){
             prd -> abscissa = i;
             prd -> ordinate = 0;
             return prd;
        }
    }
   
   for(int j = 0; j < SIZE; j++){                       //column checking

       if(matrix[0][j] == mark && matrix[1][j] == mark && matrix[2][j] != 'X' && matrix[2][j] != 'O'){
             prd -> abscissa = 2;
             prd -> ordinate = j;
             return prd;
        }
        if(matrix[0][j] == mark && matrix[2][j] == mark && matrix[1][j] != 'X' && matrix[1][j] != 'O'){
             prd -> abscissa = 1;
             prd -> ordinate = j;
             return prd;
        }
        if(matrix[2][j] == mark && matrix[1][j] == mark && matrix[0][j] != 'X' && matrix[0][j] != 'O'){
             prd -> abscissa = 0;
             prd -> ordinate = j;
             return prd;
        }
   }

   // diagonal checking / direction

   if(matrix[2][0] == mark && matrix[1][1] == mark && matrix[0][2] != 'X' && matrix[0][2] != 'O'){
       prd -> abscissa = 0;
       prd -> ordinate = 2;
       return prd;
   }
    if(matrix[2][0] == mark && matrix[0][2] == mark && matrix[1][1] != 'X' && matrix[1][1] != 'O'){
       prd -> abscissa = 1;
       prd -> ordinate = 1;
       return prd;
   }
    if(matrix[1][1] == mark && matrix[0][2] == mark && matrix[2][0] != 'X' && matrix[2][0] != 'O'){
       prd -> abscissa = 2;
       prd -> ordinate = 0;
       return prd;
   }

   // diagonal checking \ direction

   if(matrix[0][0] == mark && matrix[1][1] == mark && matrix[2][2] != 'X' && matrix[2][2] != 'O'){
       prd -> abscissa = 2;
       prd -> ordinate = 2;
       return prd;
   }
    if(matrix[2][2] == mark && matrix[0][0] == mark && matrix[1][1] != 'X' && matrix[1][1] != 'O'){
       prd -> abscissa = 1;
       prd -> ordinate = 1;
       return prd;
   }
    if(matrix[1][1] == mark && matrix[2][2] == mark && matrix[0][0] != 'X' && matrix[0][0] != 'O'){
       prd -> abscissa = 0;
       prd -> ordinate = 0;
       return prd;
   }

   else return NULL;

}


bool checkWin(char matrix[SIZE][SIZE]){

    for(int i = 0; i < SIZE; i++){      //row checking (column lined up)

        if((matrix[i][0] == matrix[i][1]) && (matrix[i][0] == matrix[i][2]) && (matrix[i][0] != ' ')){

            if(matrix[i][0] == 'X')
               printf("\t \t player 1 Won!\n");

           else 
              printf("\t \t player 2 Won!\n");
        
        return 1;
        }
    }

    for(int j = 0; j < SIZE; j++){      //column checking (row lined up)

        if((matrix[0][j] == matrix[1][j]) && (matrix[0][j] == matrix[2][j]) && (matrix[0][j] != ' ')){
          if(matrix[0][j] == 'X')
               printf("\t \t player 1 Won!\n");

           else 
              printf("\t \tplayer 2 Won!\n");
        
        return 1;
        }
    }

    if((matrix[0][0] == matrix[1][1]) &&(matrix[0][0] == matrix[2][2]) && (matrix[0][0] != ' ')){    //diagonal checking \ direction
      
      if(matrix[0][0] == 'X')
               printf("\t \t player 1 Won!\n");

      else 
              printf("\t \t player 2 Won!\n");
        
        return 1;
    
    }

     if((matrix[0][2] == matrix[1][1]) && (matrix[0][2] == matrix[2][0]) && (matrix[0][2] != ' ')) {  //diagonal checking / direction
     
      if(matrix[0][2] == 'X')
               printf("\t \t player 1 Won!\n");

           else 
              printf("\t \t player 2 Won!\n");
        
        return 1;
     }

     
      return 0;

}

bool checkWinComp(char matrix[SIZE][SIZE]){             //extremely stupid function, wasteful time complexity; need to do something about it

    for(int i = 0; i < SIZE; i++){      //row checking (column lined up)

        if((matrix[i][0] == matrix[i][1]) && (matrix[i][0] == matrix[i][2]) && (matrix[i][0] != ' ')){

            if(matrix[i][0] == 'X')
               printf("\t \t The computer has won!\n");

           else 
              printf("\t \t The user has Won!\n");
        
        return 1;
        }
    }

    for(int j = 0; j < SIZE; j++){      //column checking (row lined up)

        if((matrix[0][j] == matrix[1][j]) && (matrix[0][j] == matrix[2][j]) && (matrix[0][j] != ' ')){
          if(matrix[0][j] == 'X')
               printf("\t \t The computer has won!\n");

           else 
              printf("\t \t The user has Won!\n");
        
        return 1;
        }
    }

    if((matrix[0][0] == matrix[1][1]) &&(matrix[0][0] == matrix[2][2]) && (matrix[0][0] != ' ')){    //diagonal checking \ direction
      
      if(matrix[0][0] == 'X')
               printf("\t \t The computer has won!\n");

      else 
              printf("\t \t The user has Won!\n");
        
        return 1;
    
    }

     if((matrix[0][2] == matrix[1][1]) && (matrix[0][2] == matrix[2][0]) && (matrix[0][2] != ' ')) {  //diagonal checking / direction
     
      if(matrix[0][2] == 'X')
               printf("\t \t The computer has won!\n");

           else 
              printf("\t \t The user has Won!\n");
        
        return 1;
     }

     
      return 0;

}




bool generateMatrix(char matrix[SIZE][SIZE], int i, int j, char val){

for(int a = 0; a < SIZE; a++){
    for(int b = 0; b < SIZE; b++){
        if(matrix[a][b] != 'X' && matrix[a][b] != 'O')
           matrix[a][b] = ' ';
    }
}
    if(matrix[i][j] != 'X' && matrix[i][j] != 'O')
        matrix[i][j] = val;

     printf("\t \t ------------\n");
    for(int k = 0; k < SIZE; k++){
        printf("\t \t %c | %c | %c\n",matrix[k][0],matrix[k][1],matrix[k][2]); 
        printf("\t \t ------------\n");
    
    }

 return     checkWin(matrix);  
} 

bool generateCompMatrix(char matrix[SIZE][SIZE], int i, int j, char val){          //again, another stupid code. Bad time complexity. Do something about it.

for(int a = 0; a < SIZE; a++){
    for(int b = 0; b < SIZE; b++){
        if(matrix[a][b] != 'X' && matrix[a][b] != 'O')
           matrix[a][b] = ' ';
    }
}
    if(matrix[i][j] != 'X' && matrix[i][j] != 'O')
        matrix[i][j] = val;

     printf("\t \t ------------\n");
    for(int k = 0; k < SIZE; k++){
        printf("\t \t %c | %c | %c\n",matrix[k][0],matrix[k][1],matrix[k][2]); 
        printf("\t \t ------------\n");
    
    }

 return     checkWinComp(matrix);     
    
}

bool matrixFull(char matrix[SIZE][SIZE]){

    for(int a = 0; a < SIZE; a++){
        for(int b = 0; b < SIZE; b++){
        if(matrix[a][b] != 'X' && matrix[a][b] != 'O')
           return false;        // there's still some space in the matrix
    }
}
return true;    // matrix is full
}

void multiplayer(char matrix[SIZE][SIZE]){

    int x = 0;
    int y = 0;
    bool flag = false;              // flag == true means that it's still player2 's turn

    printf("Player 1 plays X and player 2 plays O\n\n");

        printf("Note that the 3x3 matrix starts from indices 0 to 2 for both columns, and rows. So for example, entering row as 1 and column as 1 would mark the middle position in the matrix.\n\n");


        printf("If you want to quit mid-game, enter any integer such that (i,j) cannot be the address of a point in a 3 by 3 matrix, rows(i) and columns(j) both going from 0 to 2.\n");

            while(!matrixFull(matrix)){
            
                if(!flag){                          //check if it's still player 2's turn (previous turn was an overwrite attempt)
                    printf("\n\t what row number(0 to 2) do you choose Player 1? ");
                    scanf("%d", &x);
                    printf("\t And what column number (0 to 2) do you choose Player 1? ");
                    scanf("%d", &y);
                }


                if(!(x >= 0 && x < SIZE) || !(y >= 0 && y < SIZE))       //if bad input, quit
                    break;

                // check for overwritting attempt by player 1:
                if(!flag && (matrix[x][y] == 'X' || matrix[x][y] == 'O')){              //!flag tells if it's still player 1's turn or not
                    printf("\t \t Player 1, you can't overwrite in the grid! Try again!\n");
                    continue;
                }
                if(!flag){
                    system("clear");
                    printf("\n\n\n");
                    if(generateMatrix(matrix, x, y, 'X')){
                            printf("\t\t\t\t Game Over");
                            break;
                    }
                }

                if(!matrixFull(matrix)){
                    printf("\n \t  what row number (0 to 2) do you choose Player 2? ");
                    scanf("%d", &x);
                    printf("\t And what column number (0 to 2) do you choose Player 2? ");
                    scanf("%d", &y);

                    if(!(x >= 0 && x < SIZE) || !(y >= 0 && y < SIZE))       
                        break;

                    // check for overwritting attempt by player 2:
                    if(matrix[x][y] == 'X' || matrix[x][y] == 'O'){
                        printf("\t \t You can't overwrite a previous entry in the grid Player 2! Try again.\n");
                        flag = true;                //flag that it's still player 2's turn
                        continue;
                    }
                    flag = false;                  

                    system("clear");
                    printf("\n\n\n");
                    if(generateMatrix(matrix, x, y, 'O')){
                        printf("\t\t\t\t Game Over");
                        break;
                    }
                }
                else printf("Match is a Draw! Game over\n");
            }

}

void computerMove(char matrix[SIZE][SIZE]){

    int i, j;
    bool Comp_marked = false;  
    prediction* p = NULL;

    p = predictWin(matrix, 'X');

    if(p != NULL){      // prediction is made for computer to be winning as 1st priority

        i = p->abscissa;
        j = p->ordinate;

    }

    else if ((p = predictWin(matrix, 'O')) != NULL){        // prediction is made to save a match point from the user

        i = p->abscissa;
        j = p->ordinate;

    }

    else{

        i = rand() % 3;
        j = rand() % 3;
    
    }

        if(matrix[i][j] != 'X' && matrix[i][j] != 'O'){
            system("clear");
            generateCompMatrix(matrix, i, j, 'X');
        }

        else
            computerMove(matrix);
        

}


int main(){

    system("clear");
    
    char matrix[SIZE][SIZE];
    // char playAgain;
    char gameMode;

    printf("Do you want to play multiplayer or vs Computer? (type m for multiplayer and c for vs computer)\n");
    scanf("%c", &gameMode);

    if(gameMode == 'm'){

        multiplayer(matrix);

        // printf("\nDo you want to play multiplayer mode again? (y/n)");           //again, Idk why this isn't working, try again later
        // scanf("%c", &playAgain);
        // if(playAgain == 'y' || playAgain == 'Y'){
        //   system("clear");
        //   matrix[SIZE][SIZE];
        //   multiplayer(matrix);
        // }
    }

    else if (gameMode == 'c'){

        int x, y;

        printf("Computer plays X, and user plays O\n");


        while(!matrixFull(matrix)){
            
            printf("\n\t what row number(0 to 2) do you choose? ");
            scanf("%d", &x);
            printf("\t And what column number (0 to 2) do you choose? ");
            scanf("%d", &y); 
            
            system("clear");
            // if(matrix[x][y] == 'X' || matrix[x][y] == 'O')
            //     printf("can't overwrite!");
            //   continue;
            if(generateCompMatrix(matrix, x, y, 'O')) break;

            if(!matrixFull(matrix)){

            computerMove(matrix);
            if(checkWinComp(matrix)) break;
            }
        }
    }

    else printf("unaccaptable game mode");
}
