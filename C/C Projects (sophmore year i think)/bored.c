#include <stdio.h>

main(){
int input;
int list[100][100];

printf("Input: ");
scanf("%d",&input);

for(int i=0;i<input;i++){
    for(int j=0;j<input;j++){
        list[i][j]=j+1;
        printf("%d ",list[i][j]);
    }
            printf("\n");
}


}
