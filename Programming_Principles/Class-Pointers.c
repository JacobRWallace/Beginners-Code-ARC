
#include<stdio.h>

//POINTERS
//main memory is divided into bytes, each byte is capable of storing eight bits
//each byte has a unique address

//POINTER VARIABLES
//each variable in a program occupies one or more bytes of memory
//the address of the first byte is said to be the address of the variable
//Addresses can be stored in special pointer variables

//When pointer variable is declared its name must be preceded by an asterisk: int *p;
//p is a pointer variable capable of pointing to objects of type int.
//We say object instead of variable since it references any kind of data.

// int*p points to integers
// double *q points to doubles
// float *r points to floats

//to find the address of a variable, we use the & (address) operator.
//int *p points to nowhere in particular; it is crucial to initialize p

main(void){
int *q,a=10,*p; //sets variables

printf("@ Value: a = %d",a); //prints a what it was set to
printf("\n\n");

q=&a; //q is the address a
p=q; //setting pointer q point to same address as p
*p=20; //since pointers p and q point to the same address, changing the value of address pointer p points to changes pointer q's value at its address (it overrides)

printf("Value: a = %d",a);
printf("\n");
printf("Value: *p = %d",*p);
printf("\n");
printf("Value: *q = %d",*q);
printf("\n\n");

*q = 100;//pointer *q also points to the same address as *p so it will change the value of a=10 to a=100

printf("Value: a = %d",a);
printf("\n");
printf("Value: *p = %d",*p);
printf("\n");
printf("Value: *q = %d",*q);
printf("\n");
/*
int a=10, *p=&a, b[6]={123456,88,2,69,1,0},*q=b,k=10;
//p=&a; //could do it here



printf("Value P: %d\n",*p);
printf("Address P: %d\n",p);
printf("\n");
printf("Value Q: %d\n",*q);
printf("Address Q: %d\n",q);
printf("\n");
printf("Value K: %d\n",*&k); //"*" and "&" cancel each other out.
printf("Address K: %d\n",&k);
*/
}
