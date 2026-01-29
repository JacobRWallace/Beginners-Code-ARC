// "\033[0;31m" = RED
// "\033[1;32m" = GREEN
// "\033[0;33m" = YELLOW
// "\033[1;35m" = PINK (REALLY LIGHT PURPLE)
// "\033[0;36m" = CYAN

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>//makes toupper work

#include <math.h>
#include <time.h>

void StartGame(){
printf("Welcome to the game!\n");
getch();
printf("Every decision you make will alter the game's experience...\n");
getch();
system("cls");
printf("You walk outside your house.\n");
getch();
printf("A wizard greets you with a magical request...\n");
getch();
system("cls");

//Wizard Introduction
printf("Wizard: Hello I am wizard faggot.\n");
getch();
printf("Would you prefer a sword [1] or a MAGIC WAND! [2]\n");
}

int GetOption(){
char input;
invalid:
scanf(" %c",&input);
if ((input=='1')|(input=='2')){
    system("cls");
    if(input=='1')
        return 1;
    if(input=='2')
        return 2;}
printf("\033[0;31mInvalid Input!\033[0m Enter 1 or 2\n");
goto invalid;
}

int option;
void main(){
//Start the Journey!
StartGame();

//option 1
option=GetOption();
if(option==1)

if(option==2)


}
