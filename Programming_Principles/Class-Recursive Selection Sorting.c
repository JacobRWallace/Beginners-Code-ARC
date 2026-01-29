#include<stdio.h>

int sortlist(int arr[],int n){
    int arr[];
    if (n<=1){
        return 1;}
    int max_id=0;
    for(int i=0;i<n;i++){
        if(arr[i]>arr[max_id])
            max_id=i;
    }
    int temp=arr[max_id];
    arr[max_id]=arr[n-1];
    arr[n-1]=temp;

    sortlist(arr[],n-1);
    return;
}

int main(void){
int a[5]={23,5,3,0,1};
for (int=0;i<5;i++){
    printf("%d",a[i]);
sortlist(a[],5);
printf("%d",a[i]);
for (int=0;i<5;i++){
    printf("%d",a[i]);
}
}
