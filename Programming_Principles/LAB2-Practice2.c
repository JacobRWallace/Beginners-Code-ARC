#include<stdio.h>

main(void){

printf("\033[0;36mCalculator Options:\033[0m\n\n");
printf("1. Addition\n");
printf("2. Subtraction\n");
printf("3. Multiplication\n");
printf("4. Divison\n\n");
printf("Choose Option: ");
int option,value1,value2,calculation;

scanf("%d",&option);
if(option>4 || option<0){
    printf("\033[0;31mInvalid Input!\033[0m\n");
}
else{

printf("\n");
printf("\033[0;31mSelected: \033[0m");


switch(option){

//addition
case 1:
    printf("Addition\n");
    //get values
    printf("Enter Value 1: ");
    scanf("%d",&value1);
    printf("Enter Value 2: ");
    scanf("%d",&value2);

    //calculation
    calculation = value1 + value2;
    printf("\033[0;32m%d + %d = %d\033[0m",value1,value2,calculation);
    break;

//subtraction
case 2:
    printf("Subtraction\n");
    //get values
    printf("Enter Value 1: ");
    scanf("%d",&value1);
    printf("Enter Value 2: ");
    scanf("%d",&value2);

    //calculation
    calculation = value1 - value2;
    printf("\033[0;32m%d - %d = %d\033[0m",value1,value2,calculation);
    break;

//multiplication
case 3:
    printf("Multiplication\n");
    //get values
    printf("Enter Value 1: ");
    scanf("%d",&value1);
    printf("Enter Value 2: ");
    scanf("%d",&value2);

    //calculation
    calculation = value1 * value2;
    printf("\033[0;32m%d * %d = %d\033[0m",value1,value2,calculation);
    break;

//division
case 4:
    printf("Divison\n\n");
    //get values
    printf("Enter Value 1: ");
    scanf("%d",&value1);
    printf("Enter Value 2: ");
    scanf("%d",&value2);

    //calculation
    calculation = value1 / value2;
    printf("\033[0;32m%d / %d = %d\033[0m",value1,value2,calculation);
    break;
}
}
}
