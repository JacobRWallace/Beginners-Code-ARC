#include<stdio.h>

void increment_pass_by_value(int x){
    x++;
}
void increment_pass_by_reference(int *x){
    (*x)++;
}

/*
//THIS IS WRONG
int *f(){
    int i;
    return &i; //never return the address of a function variable
}
*/

void main(){

//good note
int num=5;
printf("Value Num Before Function: %d\n",num);

//doesn't increase
/*
increment_pass_by_value(num);
printf("Value Num After Function: %d\n",num);
*/

//increases value
increment_pass_by_reference(&num);
printf("Value Num After Function: %d\n",num);


}
