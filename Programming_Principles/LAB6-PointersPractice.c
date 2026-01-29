#include<stdio.h>
#include<stdlib.h>



void main(){
    //PROBLEM

    //1. make t point to c and change to 555
    //2. change value of c again using direct assignment. Verify t points to the value by printing the result of dereferencing it.
    //3. Fix the code if added:
    /*
    int *v=&t;
    printf("%d\n",*v)
    */

    /*
    int a = 42;
    int b = 7;
    int c = 999;
    int *t = &a;
    int *u = NULL;
    printf("%d% d\n", a, *t);

    c=b;
    u=t;
    printf("%d %d\n", c, *u);

    a=8;
    b=8;
    printf("%d %d %d %d\n", b, c, *t, *u);

    *t=123;
    printf("%d %d %d %d %d\n", a, b, c, *t, *u);
    */

    //ANSWER (i didn't answer it lol)
    int a = 42;
    int b = 7;
    int c = 999;
    int *t = &a;
    int *u = NULL;
    printf("%d% d\n", a, *t);

    c=b;
    u=t;
    printf("%d %d\n", c, *u);

    a=8;
    b=8;
    printf("%d %d %d %d\n", b, c, *t, *u);

    *t=123;
    printf("%d %d %d %d %d\n", a, b, c, *t, *u);
}
