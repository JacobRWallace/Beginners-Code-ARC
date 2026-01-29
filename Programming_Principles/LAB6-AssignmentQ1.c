// "\033[0;31m" = RED
// "\033[1;32m" = GREEN
// "\033[0;33m" = YELLOW
// "\033[1;35m" = PINK (REALLY LIGHT PURPLE)
// "\033[0;36m" = CYAN

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

multi(int x,int y){
if(y==0)
    return 0;//base case
else
    return y == 0 ? x : x+multi(x,y-1);//recursive function
}

int a, b, c;
int main(){

printf("Value 1: ");
scanf(" %d",&a);

printf("Value 2: ");
scanf(" %d",&b);

int temp=multi(a,b);
printf("%d\n",temp);
}
