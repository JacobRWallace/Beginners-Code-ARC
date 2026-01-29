#include<stdio.h>

char input;
scanf("%c",&input);

/*
if (input=="Y"){
goto skip;
}
else
*/

void main(){

int a[10]={1,2,3,4,5,6,7,8,9,10},*p;
p=&a[0];//sets p pointing to address a[0]
int *q=&a[4];
printf("Print P: %d\n",p);//prints address
printf("Print *P: %d\n",*p);//prints value @ address

//practice
for(int i=0;i<10;i++){
    printf("Test: %d\n",a[i]);
}
}

skip:
void main1(){
printf("hello world!");
}
