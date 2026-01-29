// "\033[0;31m" = RED
// "\033[1;32m" = GREEN
// "\033[0;33m" = YELLOW
// "\033[1;35m" = PINK (REALLY LIGHT PURPLE)
// "\033[0;36m" = CYAN

//immaMakeSomethingIDK.c

#include <stdio.h> //Guess the number. (Higher or lower)
#include <time.h> //makes srand work?
#include <conio.h> //makes "toupper" work.
#include <stdbool.h> //makes bool work, stupid you have to import this shit.

struct Settings {
    int maxRange;
    int lives;
    int hintsOn;
};

printTitle(isCustom){
    //Print title when playing
    if(isCustom==false){
        printf("\033[1;35mGuess the Number!\033[0m\n");
        printf("\033[1;35m=================\033[0m\n");
    }
    else{
        printf("\033[1;35mGuess the Number! [Custom Match]\033[0m\n");
        printf("\033[1;35m================================\033[0m\n");
    }
}

int input, guesses=0, startedLives, random;
int hintMSG=0, errorMSG=0, playing=1, settingsRepeat=1;
char inputC;
bool isCustom = false;

void main(){

struct Settings settings = {10,3,1};

//while(1){ //loop game
//system("cls"); //clear screen when looped.

//print title & menu
printf("\033[1;35mWelcome to Guess the Number!\033[0m\n");
printf("\033[1;35m============================\033[0m\n");
printf("Enter \033[0;33m[C]\033[0m for a \033[0;33mCustom Match!\033[0m\n");
printf("\nOtherwise press any key to continue...");

//get title & menu input
inputC=toupper(getch());
system("cls");

//if c is entered; custom match settings.
if(inputC=='C'){
    //customMatch(MAXNUM,LIVES);

    isCustom = true;
    printf("\033[0;33mCustom Match Settings:\033[0m\n");
    printf("\033[0;33m======================\033[0m\n");

    //input highest value in range (1-input)
    while(settingsRepeat==1){
        printf("Enter Maximum Range: 1-");
        scanf(" %d",&input);
        if(input<1){
            system("cls");

            printf("\033[0;33mCustom Match Settings:\033[0m\n");
            printf("\033[0;33m======================\033[0m\n");

            printf("\033[0;31mInvalid Input!\033[0m\n");
        }

        else {
            system("cls");

            printf("\033[0;33mCustom Match Settings:\033[0m\n");
            printf("\033[0;33m======================\033[0m\n");
            printf("Enter Maximum Range: 1-%d\n",input);
            settings.maxRange=input;
            settingsRepeat=0;
        }
    }//while

    //input lives
    printf("Enter Number of \033[0;32mLives:\033[0m ");
    scanf(" %d",&input);
    settings.lives=input;

    printf("Hints On? [1 or 0]: ");
    scanf(" %d",&input);
    settings.hintsOn=input;

    system("cls");
}

//Store OG Values
startedLives=settings.lives;

//generate number
srand(time(NULL)); //makes the "shit" underneath work apparently...
random = rand() % settings.maxRange;

//bruteforce random number to be 1 if max range input for custom match is 1.
if(settings.maxRange==1)
    random=1;

/*
override the bullshit number generator if max range is one.
for some reason the random num gen won't just chose 1 if inputed 1 max.
*/

while(playing==1){

    system("cls");

    printTitle(isCustom);

    //print stats
    printf("Range: \033[0;33m1-%d\033[0m\n",settings.maxRange);
    //printf("Guess #: %d\n",guesses);
    printf("Lives: \033[1;32m%d\033[0m\n",settings.lives);

    //hint messages
    if(hintMSG==1)
        printf("\033[1;32mGo Lower!\033[0m\n");
    if(hintMSG==-1)
        printf("\033[1;32mGo Higher!\033[0m\n");
    if(hintMSG==0)
        //printf("");
    hintMSG=0;

    //error messages
    if(errorMSG==1)
        printf("\033[0;31mInvalid Input!\033[0m\n");
    errorMSG=0;

    //get input
    printf("Input: ");
    scanf(" %d",&input);

    //if input is 0 or greater than range then error otherwise continue.
    if((input<=settings.maxRange)&&(input>0)){

        guesses++;

        //WIN
        if(input==random){
            playing=0;

            system("cls");
            printTitle(isCustom);

            //print results
            printf("\n\033[1;32mYOU WON!\033[0m\n\n");

            printf("\033[0;33mResults:\033[0m\n");
            printf("\033[0;33m=================\033[0m\n");
            printf("Range: \033[0;36m1-%d\033[0m\n",settings.maxRange);
            printf("Number Was: \033[0;36m%d\033[0m\n",random);
            printf("Guesses: \033[0;36m%d\033[0m\n",guesses);
            printf("Lives Left: \033[0;36m%d\033[0m\n",settings.lives);
            //printf("Lives Started With: \033[1;32m%d\033[0m\n",startedLives);
            if(isCustom==1){
                printf("Hints On: ");
                if(settings.hintsOn==1)
                    printf("\033[1;32mTrue\033[0m\n");
                else
                    printf("\033[0;31mFalse\033[0m\n");
                }
            printf("\033[0;33m=================\033[0m\n");

            //printf("Press any key to play again..."); //enable this if get loop game to work. fucking bullshit.
            //getch(); //enable this if get loop game to work. fucking bullshit.

        }//if (win condition)


        //have to put after win because win will count as guess; deducting lives.
        settings.lives--;


        //LOST
        if((settings.lives==0)&&(input!=random)){
            playing=0;

            system("cls");
            printTitle(isCustom);

            //print results
            printf("\n\033[0;31mYOU LOST!\033[0m\n");
            printf("\033[0;31mOut of Lives!\033[0m\n\n");

            printf("\033[0;33mResults:\033[0m\n");
            printf("\033[0;33m=================\033[0m\n");
            printf("Range: \033[0;36m1-%d\033[0m\n",settings.maxRange);
            printf("Number Was: \033[0;36m%d\033[0m\n",random);
            printf("Guesses: \033[0;36m%d\033[0m\n",guesses);
            //printf("Lives Started With: \033[1;32m%d\033[0m\n",startedLives);
            if(isCustom==1){
                printf("Hints On: ");
                if(settings.hintsOn==1)
                    printf("\033[1;32mTrue\033[0m\n");
                else
                    printf("\033[0;31mFalse\033[0m\n");
                }
            printf("\033[0;33m=================\033[0m\n\n");

            //printf("Press any key to play again..."); //enable this if get loop game to work. fucking bullshit.
            //getch(); //enable this if get loop game to work. fucking bullshit.

        }//if (lose condition)


        //WRONG
        if(input>random){
            if(settings.hintsOn==1)
                hintMSG=1;}
        if(input<random){
            if(settings.hintsOn==1)
                hintMSG=-1;}


    }//if (the if that detects valid input.)

    else
        errorMSG=1;


    }//while (playing game)


//}//while (loop game)

}//main
