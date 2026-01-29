#include<stdio.h>
int main(){
/*
int  a[]={[12]=13,[5]=5};
//int l=sizeof(a)/sizeof(a[0]);
int l=sizeof(a)/sizeof(a[0]);
printf("length=%d\n",l);


for(int i=0;i<l;i++)
    printf("%d\n",a[i]); */
int n;
scanf("%d",&n);
int a[n][n];
//={[0][0]=1,[1][1]=1,[2][2]=1,[3][3]=1};

for(int i=0;i<n;i++){
 for(int j=0;j<n;j++)
    printf("%d ",a[i][j]);
     printf("\n");
}




}