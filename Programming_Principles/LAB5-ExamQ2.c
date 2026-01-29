// "\033[0;31m" = RED
// "\033[1;32m" = GREEN
// "\033[0;33m" = YELLOW
// "\033[1;35m" = PINK (REALLY LIGHT PURPLE)
// "\033[0;36m" = CYAN

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float average;
int input, search, odd, even;
myArray[14]={50,23,4,12,5,2,0,18,26,3,40,20,15,66};

searchElement(){
    printf("Enter Value to Search For: \033[0;32m");
    scanf(" %d", &search);
    printf("\033[0m");

    for(int i=0;i<14;i++)
        if((myArray[i])==search)
            printf("Number Found at Index: \033[0;32m%d\033[0m\n",i);
}

findAverage(){

for(int i=0;i<14;i++)
    //average=50+23+4+12+5+2+0+18+26+3+40+20+15+66;
    average+=myArray[i];
average=average/14;
printf("Average of Array values: \033[0;31m%.2f\033[0m\n",average);
}

count(){

for(int i=0;i<14;i++)
    if(((myArray[i])%2)==0){
        printf("Number: %d = \033[1;32mEven\033[0m\n",myArray[i]);
        even++;
}
    else{
        printf("Number: %d = \033[0;31mOdd\033[0m\n",myArray[i]);
        odd++;
    }
printf("Number of Even Numbers: \033[0;32m%d\033[0m\n",even);
printf("Number of Odd Numbers: \033[0;31m%d\033[0m\n",odd);
}

int main(){
printf("\033[0;32mOptions:\033[0m\n");
printf("\033[0m[1] = Search Element\033[0m\n");
printf("\033[0m[2] = Find Average\033[0m\n");
printf("\033[0m[3] = Count\033[0m\n");
while(1){
    printf("Input: ");
    scanf(" %d",&input);
    switch(input){
        case 1:
            searchElement(myArray[14]);
            break;
        case 2:
            findAverage(myArray[14]);
            break;
        case 3:
            count(myArray[14]);
            break;
    }//switch
}//while
}//main
