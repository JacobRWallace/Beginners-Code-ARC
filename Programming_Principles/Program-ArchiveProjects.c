
#include<stdio.h>

main(void) {

    //RETURN OPTION
    //returnmenu:

    //Welcome Screen
    printf("\033[0;36mWelcome to Archive!\033[0m\n");
    printf("Options:\n\n1: Input/3.14 + Option to Add!\n\n2: Count to a number!\n\n");
    printf("Input:\033[0;31m");
    //User input choose option
    float minput;
    scanf("%f",&minput);

    //Option 1
    if (minput==1) {
    printf("\nProgram 1:\033[0m\n");

        //Project 1 (First code project I made in C)
        int sub1(void); {

            //RETURN OPTION
            //printf("\033[0;36mX = Return to Menu\033[0m\n");

            //set variables
            float input,temp,addt,temp1,debug1;
            //enter number set to var input
            printf("Enter a Number:");
            scanf("%f", &input);
            //calculate and print
            temp=(input/3.14);
            printf("Your Input Divided By \033[0;33m3.14\033[0m: %0.5f\n",temp);
            //add function
            printf("Would you like to Add? (1=Y/2=N):");
            scanf("%f", &addt);
            //Detect input and loop with "x:"
            x:
            if (addt==1){
                if (debug1<1) {
                    printf("SELECTED: Adding\n");
                    debug1=1;}
                printf("Enter Value to Add to: \033[0;32m%0.5f\033[0m\n\033[0;31m",temp);
                scanf("%f", &temp1);
                //printf("\033[0mResult of Addition: \033[0;32m%0.5f\033[0m\n",temp1+temp);
                printf("\033[0m%0.2f",temp1);
                printf(" + %0.2f = ",temp);
                temp+=temp1;
                printf("%0.2f\n",temp);
                goto x;}
            else if (addt==2){
                printf("Skipping Adding Process");}
            else {
                printf("Unrecognized Command");}
                }
    }

    //Option 2 (Second code project I made in C)
    else if (minput==2) {
    printf("\nProgram 2:\033[0m\n");
        int sub2(void); {
            int input1,rate;
            int i=0;
            printf("Enter Value to Stop at: ");
            scanf("%d", &input1);
            printf("Counting Speed (100000 = 1s): ");
            scanf("%d", &rate);
            y:
            if (input1>i) {
                i++;
                printf("Value: %d\n",i);
                usleep(rate);
                goto y;}
            else {
                printf("Finished Counting");}}}
}
