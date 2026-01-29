#include <stdio.h>
#include <string.h>

float main(){

//variables
int accnum;
float outmin,bill,base_charge,mins,minutes,daymin,nightmin;
char input[1];


//enter account number
printf("Enter Account number:");
scanf("%d",&accnum);

//choose service plan (premium or regular)
printf("Choose a service plan: \nP = Premium Plan\nR = Regular Plan\nInput:");
scanf("%s",&input);

//IF PREMIUM
if (strcmp(input,"P")==0||strcmp(input,"p")==0) {
    base_charge = 25;
    printf("\nEnter Minutes Consumed During...\nDay(6AM - 6PM in Minutes):");
    scanf("%f",&daymin);
    printf("Night(6PM - 6AM in Minutes):");
    scanf("%f",&nightmin);

    if (nightmin>720 || daymin>720){
        //error for exceeding 720 minutes for minutes during 12 hours
        printf("\033[0;31mInvalid Input!:\nExceeded 720 Minutes! Not that many minutes during day/night time.\033[0m");
    }
    else{
        daymin=daymin-75;
        if (daymin<0){
        daymin=0;
        }
        nightmin=nightmin-100;
        if (nightmin<0){
        nightmin=0;
        }
        //printf("DEBUG: Day input-75: %f\n",daymin);
        //printf("DEBUG: Night input-100: %f\n",nightmin);

        minutes=nightmin*0.05+daymin*0.1;
        outmin=daymin+nightmin;
        }
}

//IF REGULAR
else if(strcmp(input,"R")==0||strcmp(input,"r")==0){
    base_charge = 10;
    printf("\nEnter Minutes Consumed:\n");
    scanf("%f",&mins);

    mins=mins-50;
    if (mins<0){
        mins=0;
    }
    printf("DEBUG: Day input-50: %f.4\n",mins);
    minutes=mins*0.2f;
    outmin=mins;


    //printf("%f",mins);
    //printf("%f",minutes);
    }

//IF INVALID
else{
    printf("\033[0;31mInvalid Input!\033[0m");
    }

//print bill
printf("\n");
printf("Account Number: %d\n",accnum);
bill = base_charge + minutes;
//printf("Minutes: %0.2f\n",minutes);
//printf("Base Charge: %0.2f\n",base_charge);
printf("Service: ");
if (strcmp(input,"P")==0||strcmp(input,"p")==0) {
    printf("\033[0;33mPremium\033[0m\n");
}
else {
    printf("Regular\n");
}
printf("Minutes: %f\n",outmin);
printf("Bill Amount: %f\n",bill);

}
