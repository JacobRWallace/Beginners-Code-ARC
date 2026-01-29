#include<stdio.h>
#include<stdlib.h>



void main(){
    int y;
    y = 6;
    int *p;
    p = NULL; //always set pointer to null if not defined. (its just better)
    p = &y;
    printf("Pointer value of p is memory address: %p\n",p);
    printf("Dereferenced value of p is %d, and y = %d\n",&p,*p);

int myArray[] = {1, 2, 3, 4, 5};
    printf("myArray: %p\n",(myArray));//original
    printf("myArray+1: %p\n",(myArray+1));//4 value difference from original
    printf("myArray+2: %p\n",(myArray+2));//8 value difference from original
    printf("&myArray[2]: %p\n",(&myArray[2]));
    printf("*(myArray+1): %p\n",*(myArray+1));
    printf("\n");
}
