#include <stdio.h>
#include <stdlib.h>

void reverseArray(int *p, int size){
int *start = p; //first element
int *end = p+(size-1); //want to point at the end of array (last element)
while(start<end){
    int temp=*start; //swap
    *start=*end;     //swap
    *end=temp;       //swap
    start++; //move start pointer to the right
    end--; //move end pointer to the left
    return;
    }
}

void main(){

int myArray[5]={1, 2, 3, 4, 5};
int size=sizeof(myArray)/sizeof(myArray[0]);



for(int i=0;i<5;i++){
    printf("%d",myArray[i]);
}
}
