
#include<stdio.h>


//EXAMPLE 1
/////////////////////////

//structure
struct test
{
int number;
char name[20];
int on_hand;
}
a={21,"Hello World!",2},
btest={.name="Hello World!"};

//function
void print_struct(struct test x){
    printf("x.number = %d\n",x.number);
    printf("x.name = %s\n",x.name);
    printf("x.on_hand = %d\n",x.on_hand);
}
/////////////////////////

//(structure that imports a new item into -> struct test??)
struct test function1(int a, char n[], int b){
    struct test p;
    p.number=a;
    strcpy(p.name,n);//Copy a string into variable
    p.on_hand=b;
    return p;
};

void main(){
    //print_struct(a);
    //print_struct(btest);
    struct test b = function1(200,"Hard Disk",20);
    print_struct(b);
}
