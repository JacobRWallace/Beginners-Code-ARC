#include<stdio.h>
//arrays
main(void) {
//1,2,3,4,5,6,7,8,9,10
//list cant exceed or under meet the 10 in brackets at "int a[10]="
//a[10] can be blank: a[]

/*

int a[]={1,2,3,4,5,6,7,8,9,10,11,12,13};

int len1=sizeof(a)/sizeof(a[0]);
//sizeof finds the length of a undefined length array
//takes bytes and divides by 4 to give 13 //sizeof(a[0]) gets a value of 104
//int l=sizeof(a); //finds the size in bytes which is 53

printf("Size of array a: %d\n",len1);

printf("\nList a:\n");
for(int i=0;i<10;i++)
    printf("%d\n",a[i]);

//C99 Initializers
int b[]={[3]=1,[5]=2,[9]=3};
int len2=sizeof(b)/sizeof(b[0]);
printf("\nSize of array b: %d\n",len2);

printf("\nList b:\n");
for(int i=0;i<10;i++)
    printf("%d\n",b[i]);

*/

//multidimensional arrays
//to access element of m in row i, column j, we must write m[i][j]
int n;
scanf("%d", &n);
int a[n][n];
//int a[4][4]={[0][0]=1,[1][1]=1,[2][2]=1,[3][3]=1}};

for(int i=0;i<n;i++){
    for(int j=0;j<n;j++)
    printf("%d ",a[i][j]);
    printf("\n");
    }

/*
int a[3][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};

for(int i=0;i<3;i++){
    for(int j=0;j<4;j++)
    printf("%d ",a[i][j]);
    printf("\n");
    }
*/

}
