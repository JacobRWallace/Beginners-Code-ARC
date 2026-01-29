#include <stdio.h>
#include <stdlib.h>
#define ARRLEN 3

int n = 3;
int myArrA[ARRLEN][ARRLEN];
int myArrB[ARRLEN][ARRLEN];
int myArrR[ARRLEN][ARRLEN];

int ranNumGen(){
    int x = rand() % 9 + 0;
    return x;
}

//Initialize Matrix
initArr(){
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            myArrA[i][j] = i;
        }
    }
}
//Multiply Matrix
mulArr(int* arr1, int* arr2){   //WORK ON THIS

    int arrR[ARRLEN][ARRLEN];

    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            for(int k=0 ; k<n ; k++){
                arrR[i][j] += myArrA[i][k] * myArrB[k][j];
            }
        }
    }
}

//Print Matrix Results
printArr(){
    printf("myArrA:\n");
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            printf("%d ", myArrA[i][j]);
        }
        printf("\n");
    }   
}

void main(){
    initArr()
}