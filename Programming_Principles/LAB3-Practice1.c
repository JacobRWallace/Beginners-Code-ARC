#include<stdio.h>

main(){
    int arr[14]={100,23,1,12,5,2,7,18,26,3,40,20,15,88};
    int search,dbg;

    printf("Enter value to search for in array: ");
    scanf("%d",&search);

    for(int i=0;i<14;i++){
        //printf("%d\n",arr[i]);
        if (arr[i]==search){
            dbg=1;
            printf("Found Result at \033[0;32mIndex: %d\033[0m",i);
        }
        /*
        else
            printf("\033[0;31mNo Results!\033[0m");
            break;
        */
    }
    if (dbg != 1)
        printf("\033[0;31mNo Results!\033[0m");
    //printf("\nTest?"); //this works AWESOME!
}
