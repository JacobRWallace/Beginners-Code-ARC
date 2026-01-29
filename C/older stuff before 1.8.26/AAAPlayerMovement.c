#include <stdio.h>

#define X 20
#define Y 20

char map[X][Y];
player = 'O';
pX = X/2;
pY = Y/2;

void printMap(){
    // print map
    for (int i = 0; i < X; i++) {
        for (int j = 0; j < Y; j++) {
            printf("%c", map[i][j]);  
        }
        printf("\n");
    }
}

int main() {
    //initialize
    for (int i = 0; i < X; i++) {
        for (int j = 0; j < Y; j++) {
            map[i][j] = '.';
        }
    }

    while(1){

        //getch?
        printMap();
        //clear screen

    }

    return 0;
}
