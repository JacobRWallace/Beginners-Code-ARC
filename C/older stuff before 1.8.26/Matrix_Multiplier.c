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

void main(){
    
    //Initialize Matrix
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            myArrA[i][j] = i;
            myArrB[i][j] = j;
        }
    }

    //Multiply Matrix
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            for(int k=0 ; k<n ; k++){
                
                myArrR[i][j] += myArrA[i][k] * myArrB[k][j];

            }
        }
    }

    //Print Matrix Results
    printf("myArrA:\n");
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            printf("%d ", myArrA[i][j]);
        }
        printf("\n");
    }   

    printf("myArrB:\n");
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            printf("%d ", myArrB[i][j]);
        }
        printf("\n");
    }   

    printf("myArrR:\n");
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            printf("%d ", myArrR[i][j]);
        }
        printf("\n");
    }   

}