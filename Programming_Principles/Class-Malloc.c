#include<stdio.h>
#include<stdlib.h>

main(){
int *arr;
int size;
printf("Enter Size: ");
scanf(" %d",&size);

arr=malloc(size*sizeof(int));

if(arr==NULL)
    printf("memory allocation failed");

for(int i=0;i<size;i++)
    arr[i]=i*2;
for(int i=0;i<size;i++)
    printf("%d ",arr[i]);

free(arr);

}
