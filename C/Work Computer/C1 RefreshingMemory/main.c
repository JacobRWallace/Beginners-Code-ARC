#include <stdio.h>
#define LENGTH10 10

int input, arr[101];

int printArr(int arrayGiven[], int length){
    printf("Array Printed:\n");

    for(int i=0;i<length;i++){
        printf("Value: %d\n",arrayGiven[i]);
    }
    return 0;
}

int initArr(int arrayGiven[], int length){
    for(int i=0;i<length;i++){
        arrayGiven[i]=i*i;
    }
    return 0;
}

int main(){

    printf("Enter Length: ");
    scanf(" %d",&input);
    printf("Length is: %d\n\n", input);

    initArr(arr, input);

    printArr(arr, input);
    return 0;
}