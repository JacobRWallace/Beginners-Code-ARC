// "\033[0;31m" = RED
// "\033[1;32m" = GREEN
// "\033[0;33m" = YELLOW
// "\033[1;35m" = PINK (REALLY LIGHT PURPLE)
// "\033[0;36m" = CYAN

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int accnum;
char serviceCode;
double peakUsage, offPeakUsage, billa, billb, amount;

double calculateCharge(char serviceCode, double peakUsage, double offPeakUsage){
printf("\033[0mElectricity Bill:\033[0m\n");
printf("\033[1;34mAccount Number: %d\033[0m\n",accnum);
switch(serviceCode){
    case 'R':
    case 'r':
        printf("\033[0;32m[SELECTED]\033[0m = Residential\n");

        billa = 0.10*offPeakUsage;
        billb = 0.15*peakUsage;

        printf("\033[1;35mUsage in Off-Peak Hours: \033[0m%.2lf kWh\n",peakUsage);
        printf("\033[1;35mUsage in Peak Hours: \033[0m%.2lf kWh\n",offPeakUsage);

        amount = billa+billb;

        printf("\033[1;32mAmount Due: $%.2lf\033[0m\n",amount);

    break;

    case 'C':
    case 'c':

        printf("\033[0;32m[SELECTED]\033[0m = Commercial\n");

        billa = 0.15*offPeakUsage;
        billb = 0.20*peakUsage;

        printf("\033[1;35mUsage in Off-Peak Hours: \033[0m%.2lf kWh\n",peakUsage);
        printf("\033[1;35mUsage in Peak Hours: \033[0m%.2lf kWh\n",offPeakUsage);

        amount = billa+billb;

        printf("\033[1;32mAmount Due: $%.2lf\033[0m\n",amount);

    break;

}//switch
}



int main(){

printf("\033[1;32mEnter Account Number: \033[0m");
scanf(" %d",&accnum);
printf("\n");

printf("\033[1;35mEnter usage in peak hours (kWh): \033[0m");
scanf(" %lf",&peakUsage);

printf("\033[1;35mEnter usage in off-peak hours (kWh): \033[0m");
scanf(" %lf",&offPeakUsage);
printf("\n");

printf("\033[0;31m[ Enter Service Code ]\033[0m\n");
printf("\033[1;34m[R]\033[0m = Residential\n");
printf("\033[1;34m[C]\033[0m = Commercial\n");
printf("Input: ");
scanf(" %c",&serviceCode);
printf("\n");

calculateCharge(serviceCode,peakUsage,offPeakUsage);
}
