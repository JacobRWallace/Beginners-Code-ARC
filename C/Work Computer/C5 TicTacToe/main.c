#include <stdio.h>
#include <stdlib.h> //clear screen with system("cls");
#include <windows.h> //pause the program with Sleep(); //Sleep VS sleep is DIFFERENT! "Sleep" uses milliseconds while "sleep" uses seconds.

char board[3][3];
char winner;
int spacesLeft=9;

//declare fucntions
int pBoard();
int cBoard();
int checkWin();
int pWinner();
int pMove();
int cMove();
int sLeft();

int main(){

    cBoard();
    winner = ' ';
    spacesLeft = 9;
    //Play LOOP
    do{
        pBoard(board);

        //printf("DEBUG: spaces left: %d\n",spacesLeft);
        //printf("DEBUG: winner: %c\n",winner);

        /*
        int row,column;

        printf("Row #: ");      //Why won't this work.
        scanf("%d",&row);

        printf("Column #: ");
        scanf("%d",&column);

        board[row][column] = 'X';
        */

        pMove();
        cMove();
        sLeft();
        checkWin();
        system("cls");

    }while(winner == ' ');
    pBoard(board);
    pWinner();
    

    return 0;
}


int pBoard(char board[3][3]){
    
    printf(" %c | %c | %c  1\n",board[0][0],board[0][1],board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c  2\n",board[1][0],board[1][1],board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c  3\n",board[2][0],board[2][1],board[2][2]);
    printf(" 1   2   3 \n");
    return 0;

   /* CHATGPT Method
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 3 - 1) printf("|");
        }
        printf("  %d\n", i + 1);
        if (i < 3 - 1) printf("---|---|---\n");
    }
    printf(" 1   2   3 \n");
    */
}

int cBoard(){
    //initialize board
    for(int i=0; i<3 ; i++){
        for(int j=0; j<3 ; j++){
            board[i][j] = ' ';
        }
    }

    return 0;
}

int pMove(){
        int x;
        int y;

        do{
            printf("Row # (1-3): ");
            scanf("%d",&x);
            x--;

            printf("Column # (1-3): ");
            scanf("%d",&y);
            y--;

            if(board[x][y] == ' '){
                board[x][y] = 'X';
                break;
            }
            else{
                printf("Space occupied!\n");
            }
        }while(board[x][y] != ' ');

    return 0;
}

int cMove(){
        int x;
        int y;

        do{
            x = rand() % 3;
            y = rand() % 3;
            
            if(board[x][y] == ' '){
                board[x][y] = 'O';
                break;
            }
        }while(board[x][y] != ' ' && spacesLeft > 1);

    return 0;
}

int checkWin(){

    //TIE
    if(spacesLeft<=0){
        winner = 'T';
    }

    //PLAYER
    
    //Check Rows
    for(int i=0 ; i<3 ; i++){
        if((board[i][0]=='X' && board[i][1]=='X') && board[i][2]=='X') //board[y][x]
            winner = 'X';
    }

    //Check Columns
    for(int i=0 ; i<3 ; i++){
        if((board[0][i]=='X' && board[1][i]=='X') && board[2][i]=='X') //board[y][x]
            winner = 'X';
    }

    //Check Diagonals
    if((board[0][0]=='X' && board[1][1]=='X') && board[2][2]=='X'){winner='X';}
    if((board[2][0]=='X' && board[1][1]=='X') && board[0][2]=='X'){winner='X';}


    //COMPUTER

    //Check Rows
    for(int i=0 ; i<3 ; i++){
        if((board[i][0]=='O' && board[i][1]=='O') && board[i][2]=='O') //board[y][x]
            winner = 'O';
    }

    //Check Columns
    for(int i=0 ; i<3 ; i++){
        if((board[0][i]=='O' && board[1][i]=='O') && board[2][i]=='O') //board[y][x]
            winner = 'O';
    }

    //Check Diagonals
    if((board[0][0]=='O' && board[1][1]=='O') && board[2][2]=='O'){winner='O';}
    if((board[2][0]=='O' && board[1][1]=='O') && board[0][2]=='O'){winner='O';}

    return 0;
}

int sLeft(){
    spacesLeft=9;
    for(int i=0; i<3 ; i++){
        for(int j=0 ; j<3 ; j++){
            if(board[i][j]!=' '){
                spacesLeft--;
            }
        }
    }
    return 0;
}

int pWinner(){
    if(winner == 'X'){
        printf("Player Wins!\n");
    }
    else if(winner == 'O'){
        printf("Computer Wins!\n");
    }
    else{
        printf("Tie!\n");
    }
    return 0;
}