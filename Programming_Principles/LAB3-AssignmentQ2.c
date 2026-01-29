#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <math.h>

int main(){
//variables
int moves,upper,lower,x,y,num;
lower=0;
upper=3;
x=0;
y=0;

//enter moves
printf("Enter number of Moves: ");
scanf("%d",&moves);

if (moves<0)
    printf("Invalid Input!");
else

//random number
for(moves=moves;moves>=1;moves--){
    //printf("[DEBUG] moves: %d",moves);

    //random num gen given
    //srand(time(0));
    //int num = (rand() % (upper - lower + 1)) + lower;

    //random num gen better possibly
    int direction = rand() % 4;

    switch(direction){
        case 0:
            x++;
            printf("Moved \033[0;31mEast\033[0m to \033[0;31m(%d,%d)\033[0m\n",x,y);
            break;
        case 1:
            y++;
            printf("Moved \033[0;31mNorth\033[0m to \033[0;31m(%d,%d)\033[0m\n",x,y);
            break;
        case 2:
            x--;
            printf("Moved \033[0;31mWest\033[0m to \033[0;31m(%d,%d)\033[0m\n",x,y);
            break;
        case 3:
            y--;
            printf("Moved \033[0;31mSouth\033[0m to \033[0;31m(%d,%d)\033[0m\n",x,y);
            break;
        }

    //printf("[DEBUG] Number Generated: %d",num);
}
float pyth = sqrt(x*x+y*y);
printf("\033[0;32mDistance of the Path: %f\033[0m",pyth);
//increment grid position based off number generated
}
