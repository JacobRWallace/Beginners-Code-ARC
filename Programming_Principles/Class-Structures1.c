#include<stdio.h>


struct first
{
int number;
char name[20];
int on_hand;
}
a={20,"Disk Drive",15},
b={.number=23, .name="CD", .on_hand=5},
c={.name="Floppy", .on_hand=7},
//IMPORTANT:
//e = a, //this will actually duplicate a's data into e unlike you can not using a structure see EX1
d={.number=23, "Hard Disk", .on_hand=5};


/*
//EX1:
a[2]={2,42}
b=a;//this does not give a its own array it sets a to point to b's array.
*/

//New Notes:
struct
{
int a[5];
}
f,e;




void main(){

f.a[0]=1;
f.a[1]=5;
f.a[2]=7;
f.a[3]=20;
f.a[4]=99;

for(int i=0;i<5;i++)
    printf("%d\n",f.a[i]);

    printf("\na.number = %d\n",a.number);
}
