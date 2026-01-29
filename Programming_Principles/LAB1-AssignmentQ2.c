
#include<stdio.h>

int main() {

    int billamount,people;
    float tip,tippercent;

    //INPUT VALUES
    printf("Enter the Bill Amount: ");
    scanf("%d",&billamount);
    printf("Enter Tip Percentage Amount (0.10,0.15, or 0.20): ");
    scanf("%f",&tip);
    printf("Enter Amount of People: ");
    scanf("%d",&people);

    //tippercent = tip/100;

    //OUTPUT VALUES
    float tax = billamount*0.16;
    printf("Tax: %0.2f$\n",tax);

    float taxpay = billamount*1.16;
    printf("Bill + Tax: %0.2f$\n", taxpay);

    float tipperperson = ((taxpay)/people)*(tip);
    printf("Tip per Person: %0.2f$\n", tipperperson);

    float totalper = ((taxpay)/(people))+tipperperson;
    printf("Total per Person + Tip: %0.2f$\n", totalper);

    return 0;
}
