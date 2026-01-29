// "\033[0;31m" = RED
// "\033[1;32m" = GREEN
// "\033[0;33m" = YELLOW
// "\033[1;35m" = PINK (REALLY LIGHT PURPLE)
// "\033[0;36m" = CYAN

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sw=0;
gen(int x,int k){


/*
int count=x; //manipulate different variable

while(count!=0){ //increment down
    for(int i=0;i<count;i++)
        printf("*");
    count--;
    printf("\n");}

while(count<x){ //increment up
    count++;
    for(int i=0;i<count;i++)
        printf("*");
    //count++;
    printf("\n");}
*/

    for(int i=0;i<x;i++){
        printf("*");
        if (i+1==x)
            printf("\n");
            }
//printf("x: %d\n",x);
//usleep(1000000);

/*
printf("count: %d",count);
if(count!=x){
    for(int i=x;i>count;i--){
        printf("*");
        if (i+1==count)
            printf("\n");
            }
        }
*/

if(x==1){
    sw++;}//switch once hit 0 to count back up

if(sw==0)//decrement
    return gen(x-1,k);
else if(sw==1)//print 1 * (pause)
    return gen(x,k);
else if(sw==2&x!=k)//increment
    return gen(x+1,k);
}

int a, b;
int main(){

printf("Enter Value: ");
scanf(" %d",&a);

b=a;
gen(a,b);
}
