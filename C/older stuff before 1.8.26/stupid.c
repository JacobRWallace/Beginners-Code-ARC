#include <stdio.h>
#include <stdbool.h>
#define MAXLEN 10

int input;
int dataArr[MAXLEN];

void initiliazeArr(int Arr[]){
    for(int i=0;i<MAXLEN;i++){
        Arr[i] = 0;
    }
}

void printArr(int Arr[]){
printf("Array Printed: ");
    for(int i=0;i<MAXLEN;i++){
        printf("%d ",Arr[i]);
    }
}

void main(){

while(true){
    
    initiliazeArr(dataArr);
    printArr(dataArr);

    scanf("%d",&input); 
    printf("Entered: %d\n",input);

    }
}