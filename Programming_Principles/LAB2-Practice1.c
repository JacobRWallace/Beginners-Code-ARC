#include<stdio.h>

main(void){

//varibales
int hours, minutes, i;

//get hours
printf("Enter Hours: ");
scanf("%d",&hours);

//get minutes
printf("Enter Minutes: ");
scanf("%d",&minutes);

//errors
if (minutes>59 || hours<0 || minutes<0){
    printf("\033[0;31mInvalid Input!\033[0m");}
else{

//determine AM or PM
    while(hours>12){
    hours = hours-12;
    i++;
    //printf("i value: %d\n",i);
    }

//Print Results
printf("\033[0;32mTime: %d:%d\033[0m",hours,minutes);

if (i%2==0){
    printf("\033[0;32mAM\033[0m");}
else{
    printf("\033[0;32mPM\033[0m");}
}
}
