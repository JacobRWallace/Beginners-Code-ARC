#include <stdio.h>
#include <stdlib.h>

int HUBinput;

int main(void){

//fopen NOTES!: fopen ("file.txt", "x");
//x= "r"=read, "w"=creates empty file for writing(will overwrite), "a"=appends to a file(if exists just adds),"r+"=opens file to update both reading and writing, "w+"=creates empty file for reading and writing, "a+"=opens file for reading.

//good to know V
//(void)system("C:\\Users\\unkow\\Documents\\Programming Principles\\XXX - ChatGPT Fibonacci.exe");

printf("WELCOME TO CHATGPT ARCHIVE!\n");
printf("Select a Program:\n\n");
printf("1: Fibonacci Sequence\n");
printf("2: Guess The Number\n");

printf("\nInput:");
scanf("%d",&HUBinput);

switch(HUBinput){
    case 1:
        printf("Selected Option 1:\n");
        break;

    default:
        printf("Defaulted.");
    }
}
