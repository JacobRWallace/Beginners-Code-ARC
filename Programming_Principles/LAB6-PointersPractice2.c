#include<stdio.h>

//write a swap() function with the following function header:

int swap(int *p1, int *p2){
int temp = *p1;
*p1 = *p2;
*p2 = temp;
}

void main(){
int *p1, *p2;
p1=1;
p2=2;

printf("p1 = %p p2 = %p\n",p1,p2);
printf("Swapped\n");
printf("p1 = %p p2 = %p\n",swap(&p1,&p2));

}
