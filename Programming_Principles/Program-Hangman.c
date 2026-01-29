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

#define MAXNUMLIVES 5
#define MAXARRAYLEN 100

char generatedWord, input, linput;
int random, index=0, guesscount, wordcomplete=0, health=MAXNUMLIVES, guesscorrect=0, deduct=0, deductnum=0, LOOP=1, capsR=1;
char lettersUsed[26];
char selectedword[MAXARRAYLEN];
char showCorrect[];
char words[][MAXARRAYLEN]={"APPLE","BEANS","RETARD","FAGGOT","BALLS","GARYGAY","HANGMAN","INCARCERATION","PNEUMONOULTRAMICROSCOPICSILICOVOLCANOCONIOSIS","DIPSHIT","WALMART","TARGET","WEATHERFORD"};

numOfGenWords=(sizeof(words)/sizeof(words[0]));//finds length of array(i didnt use this shit but could be useful)

void main(){
//printf("numOfGenWords: %d\n",numOfGenWords);

replay:

wordcomplete=0;
capsR=1;//remind turn on caps lock

guesscount=0;
deduct=0;

health=MAXNUMLIVES; //reset health to MAXNUMLIVES

//reset lettersUsed
for(int i=0;i<26;i++){
    lettersUsed[i]=0;
}

//initialize showCorrect ="-" all across
for(int i=0;i<MAXARRAYLEN;i++){
    showCorrect[i]='-';
    //printf("%c",showCorrect[i]);
}

//randomly select word from words array

srand(time(NULL)); //makes the "shit" underneath work apparently...
int random = rand() % numOfGenWords; //<- the "shit"
strcpy(selectedword,words[random]);
//printf("random #: %d\n",random);


//loop guessing process
//printf("selectedWord: %s\n",selectedword);
while(LOOP==1){


if(capsR==1){ //Remind about caps lock!
    printf("\033[1;35m[ TURN ON CAPS LOCK! ]\033[0m\n");}
else{
    printf("\033[0;36m[ HANGMAN ]\033[0m\n");}
capsR=0;


//to find selected word length
//int g=strlen(selectedword);//strlen only works if array has a defined length at x: arr[x]
//printf("TEST BALLS: %d\n",g);



//PRINTING SHIT



//print stats
printf("\033[1;32mHealth: %d\033[0m",health);
if(deduct==1){
    deductnum++;
    printf("\033[0;31m -%d\033[0m",deductnum);}
else{
    deductnum=0;}
printf("\n");
deduct=0;
printf("Guess #: %d\n",guesscount);





//print showCorrect
for(int p=0;p<strlen(selectedword);p++){
    printf("%c",showCorrect[p]);
}
printf("\n"); //break line after printing the reveal array


//START GUESSING

back:
//input letter
printf("Guess Letter: ");
scanf(" %c",&input);
guesscount++;
//input = toupper(linput); //convert to uppercase


//check if already guessed
for(int i=0;i<26;i++){
    if(input==lettersUsed[i]){
        printf("\033[0;31mAlready Guessed: %c!\033[0m\n",input);
        goto back;}
    }
lettersUsed[index]=input;
index++;

//overwrite "-" with correct letter in showCorrect
for(int j=0;j<MAXARRAYLEN;j++){
    if(input==selectedword[j]){
        showCorrect[j]=input;
        guesscorrect=1;
        //printf("Match at index: %d\n",j);
    }
}

//deduct health if wrong
if(guesscorrect==0){
    health--;
    deduct=1;
}
guesscorrect=0;




system("cls");//Clear Console (think it uses <stdlib.h>)


//implement later perhaps
//printf("SHOW Letters Guessed #: ");



//check if word is complete
int a=0; //resets a
for(int p=0;p<MAXARRAYLEN;p++){
    if(showCorrect[p]!='-'){
        a++;
        if(a==strlen(selectedword)){
            wordcomplete=1;
        }
    }
}


//win!
if (wordcomplete==1){
    printf("\033[1;32mYOU WIN!\033[0m\n");
    if((health==MAXNUMLIVES)|(health==1))
        printf("\033[0;33mRewards: \033[0m");
        if(health==MAXNUMLIVES)
            printf("\033[0;33m[ACED]\033[0m");
        if(health==1)
            printf("\033[0;33m[SURVIVOR]\033[0m");
        printf("\n");

    printf("Word: %s\n",selectedword);
    printf("Guess Count: %d\n",guesscount);
    printf("\033[0;31mLives Lost: %d\033[0m\n",MAXNUMLIVES-health);
    printf("\033[0;32mRemaining Health: %d\033[0m\n",health);

    printf("\nPress any key to play again: ");
    getch();
    system("cls");

    return 0;
    //goto replay;

    //LOOP=0; //replay function disables this
}

//lose!
if (health==0){
    system("cls");
    printf("\033[0;31mGame Over!\033[0m\n");
    printf("Out of Lives!\n");

    /*
    int a=0,d;
    while(1){
        a++;
        if(a%2==0){
            d = "\033[0;31mGame Over!\033[0m";}
        else{
            d = "Game Over!";}
        system("cls");
        printf("%s",d);
        usleep(150000);
    }//while(1)#2
    */

    printf("Word: %s\n",selectedword);
    return 0;
    printf("\nPress any key to play again: ");
    getch();
    system("cls");

    //goto replay;

}//if for lose

}//while(1)
}//main
