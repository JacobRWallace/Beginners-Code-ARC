#include "functions.c" //quotations reference other files within main.c directory.
#include <stdio.h>

int base, power, result=NULL;

main(){
    printf("Enter base value: ");
    scanf("%d",&base);

    printf("%d^",base);
    scanf("%d",&power);

    result = toPower(base,power);
    printf("%d",result);
}