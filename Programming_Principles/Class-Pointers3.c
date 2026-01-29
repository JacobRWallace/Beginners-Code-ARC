#include<stdio.h>

void main(){
//EXAMPLE 1:
/*
int a[]={3,5,7,8,0,21},*p,*q,*r,b;
p = &a[2]; //p=2 because &a[2] is 2 due to the & symbol which gives the value of the index, not the value in the array.
//=p+2;
r = &b[0];
b = p - r;
int c = p > r; //boolean (true or false; in integer 1 or 0)
printf("%d",c);
*/

//EXAMPLE 2:
/*
int a[]={3,5,7,8,0,21},*p,*q,sum;p
for(p=&a[0];p<a[6];p++)
    sum+=*p;
printf("%d",sum);
*/

//NOTES:
//In general, a+i is the same as &a[i].
//Also, *(a+i) is equivalent to a[i].

//EXAMPLE 3:
/*
int a[10],*p;

for(p=a;p<a+10;p++)
    *p=0;

*a=10;
*(a+1)=12;
*(a+5)=20;
*(a+9)=100;

//*(p+3)=20;
//*(p+5)=100;


for(int i=0;i<10;i++)
    printf("%d\n",a[i]);
*/

//EXAMPLE 4:
//Find largest value in array function
int a[]={3,5,7,8,0,21};
int find_largest(int a[],int n){
    int i, max;

    max = a[0];
    for (i=1;i<n;i++)
        if(a[i]>max)
            max=a[i];
            printf("%d",max); //i added this
        return max;

find_largest(a[0],6);

}
}

