#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {

    //TITLE
//////////////////////////
    PlayAgain:
    printf("\033[0;33mWelcome to: Rock Paper Scissors!\033[0;m");

    //PLAY AGAIN
//////////////////////////

    PlayAgainALT:
    printf(""); //Debug to return back.

    //VARIABLES
//////////////////////////

    int input,robotinput,debug,pa;

    //ROBOT INPUT
//////////////////////////

    int lower = 1, upper = 3, count = 1;
    srand(time(0));
    //printf("The random numbers are: ");
    for (int i = 0; i < count; i++) {
        int robotinput = (rand() % (upper - lower + 1)) + lower;
        debug=robotinput;
        //printf("%d ", robotinput);
    }

    //PLAYER INPUT
//////////////////////////

    printf("\nChoose a option: \n\n1 = Rock\n2 = Paper\n3 = Scissors\n4 = Nuke!\n\nInput: ");
    scanf("%d",&input);

    //CALCULATIONS
//////////////////////////

    //printf("\nRobot's Choice: %d",debug);
    //printf("\nPlayer's Choice: %d",input);
    if (debug==input){
        if (debug==1 && input==1){
        printf("\033[0;36m[Robot Played: Rock]\033[0;m\n          VS\n\033[0;36m[Player Played: Rock]\033[0;m");
    }
        if (debug==2 && input==2){
        printf("\033[0;36m[Robot Played: Paper]\033[0;m\n         VS\n\033[0;36m[Player Played: Paper]\033[0;m");
    }
        if (debug==3 && input==3){
        printf("\033[0;36m[Robot Played: Scissors]\033[0;m\n          VS\n\033[0;36m[Player Played: Scissors]\033[0;m");
    }
        printf("\n        Draw!");
    }

    //ROBOT WINS
//////////////////////////

    else if (debug==1 && input==3){
        printf("\033[0;36m[Robot Played: Rock]\033[0;m\n          VS\n\033[0;36m[Player Played: Scissors]\033[0;m");
        printf("\n\033[0;31m     Robot Wins!\033[0;m");
    }
    else if (debug==2 && input==1){
        printf("\033[0;36m[Robot Played: Paper]\033[0;m\n         VS\n\033[0;36m[Player Played: Rock]\033[0;m");
        printf("\n\033[0;31m     Robot Wins!\033[0;m");
    }
    else if (debug==3 && input==2){
        printf("\033[0;36m[Robot Played: Scissors]\033[0;m\n          VS\n\033[0;36m[Player Played: Paper]\033[0;m");
        printf("\n\033[0;31m     Robot Wins!\033[0;m");
    }

    //PLAYER WINS
//////////////////////////

    else if (debug==3 && input==1){
        printf("\033[0;36m[Robot Played: Scissors]\033[0;m\n          VS\n\033[0;36m[Player Played: Rock]\033[0;m");
        printf("\n\033[0;32m     Player Wins!\033[0;m");
    }
    else if (debug==1 && input==2){
        printf("\033[0;36m[Robot Played: Rock]\033[0;m\n          VS\n\033[0;36m[Player Played: Paper]\033[0;m");
        printf("\n\033[0;32m     Player Wins!\033[0;m");
    }
    else if (debug==2 && input==3){
        printf("\033[0;36m[Robot Played: Paper]\033[0;m\n         VS\n\033[0;36m[Player Played: Scissors]\033[0;m");
        printf("\n\033[0;32m     Player Wins!\033[0;m");
    }
    else if (input==4){
        printf("\033[0;36mXXXXXXXXXXXXXXXXXXXXXX\033[0;m\n");
        printf("\033[0;32m     Player Wins!\033[0;m");
    }
    else {
        printf("\033[0;31mERROR!\033[0;m");
    }

    //PLAY AGAIN OPTION
//////////////////////////

printf("\n\nPlay Again?\n1 = RESTART\n2 = CLEAR + RESTART\n");
scanf("%d",&pa);
if (pa==1) {
    goto PlayAgainALT;
    }
else if (pa==2) {
    system("cls");
    goto PlayAgain;
}
}
