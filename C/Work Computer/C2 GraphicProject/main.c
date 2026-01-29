#include <stdio.h>
#include <stdlib.h> //clear screen with system("cls");
#include <windows.h> //pause the program with Sleep(); //Sleep VS sleep is DIFFERENT! "Sleep" uses milliseconds while "sleep" uses seconds.

#define LENGTH 100

char LB[LENGTH];
int pos1=0, length, speed;
float percent;

int main(){

    printf("Enter length: ");
    scanf(" %d",&length);

    printf("Enter speed (1000=1s): ");
    scanf(" %d",&speed);

    //initalize empty loading bar
    system("cls");
    for(int i=0;i<length;i++){
        LB[i]='-';
    }

    //loading animation
    for(int j=0;j<length+1;j++){

        //print loading bar
        for(int i=0;i<length;i++){
            printf("%c",LB[i]);
        }
        
        percent = ((float)pos1 / length) * 100;

        //print %
        printf("\n%.0f/100",percent);

        //printf("\n");
        Sleep(speed);
        system("cls");

        //increment █
        LB[pos1]='X';
        pos1++;
    }

    //Loading Completed!
    for(int i=0;i<length;i++){
        printf("%c",'X');
    }
    printf("\n");
    printf("Loading Completed!");
    return 0;
}