#include<stdio.h>
#include<stdlib.h>

struct point{
int x;
int y;
};

void main(){
struct point *arr;
int size;
printf("Enter Size: ");
scanf(" %d",&size);

arr=calloc(size,size*sizeof(struct point));//if malloc will print garbage values

if(arr==NULL){
    printf("memory allocation failed");
    return;
    }

printf("\n\033[0;31marr[i].x, arr[i].y print:\033[0m\n\n");

for(int i=0;i<size;i++) //calloc initializes to 0 for us
    arr[i].y=i*2;

for(int i=0;i<size;i++) {
    printf("%d ",arr[i].x);
    printf("%d \n",arr[i].y);
    }

printf("\n\033[0;31m*p print:\033[0m\n\n");

struct point *p;
p=realloc(arr,size);

for(int i=0;i<size;i++) {
    printf("%d ",(p)[i].x);
    printf("%d \n",(p)[i].y);
    }

free(arr);
return 1;
}
