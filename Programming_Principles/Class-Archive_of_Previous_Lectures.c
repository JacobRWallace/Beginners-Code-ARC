#include<stdio.h>
main(void) {

int Ginput;
printf("Choose code to run:");
scanf("%d",&Ginput);

int i;
double a[10];

switch(Ginput) {

    case 1:
        //for loop
        for (int i=0;i<5;i++) {
                for (int j=0;j<5;j++) {
                    if ((i==2)&&(j==2))
                            break;
                        printf("i=%d, j=%d\n",i,j);
                            }
                            }

    case 2:
        for (int i=0;i<5;i++) {
                printf("i=%d\n",i);
        }

    case 3:
        //while loop
        i = 10;
        while (i>0) {
            printf("T minus %d and counting\n",i);
            --i;
        }

    case 4:
        //arrays

        //a[6]=12.88;
        //printf("%1f",a[6]);

        a[0]=1; // runs 1+2+4+8=15
        printf("%d\n",a[5]);
        ++a[0];

        for (int i=0;i<=10;i++) { //idfk
            printf("Value: %d\n",a[i]);
        }



    //case 5:


    //case 6:


    //case 7:


    //case 8:


    //case 9:


    //case 10:


    //case 11:














}
}
