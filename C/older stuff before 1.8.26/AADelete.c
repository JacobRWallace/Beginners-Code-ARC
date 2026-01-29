#include <stdio.h>

void eoo(int x){
    if(x % 2 == 0){
        printf("0");
    }
    return NULL;
}

void main() {
    int x;
    scanf(" %d", &x);
    printf("Entered Value: %d\n", x);
    
    /*
    for(int i = 0; i < x; i++){
        for(int j = 0; j < x; j++){
            printf("%d ",j);
        }
        printf("\n");
    }
    */

    int m = x/2;
    printf("m: %d\n",m);
    int temp = 0;

    for(int i = 0; i < x; i++){
        if(i <= m){
            printf("%d ",i);
        }
        else{
            if(temp==0){
                printf("\n");
            }
            temp = temp + 1;
            printf("%d ",(m-temp));
        }
    }
    eoo(x);
}