#include<stdio.h>

main(){
int income, tax, taxincome;
printf("Enter a income: ");
scanf("%d",&income);

if (income<750){
    printf("\033[0;32m- Tax Bracket 1 -\033[0m\n");
    printf("0 - 749\n");

    tax = income * .01;
    taxincome = income - tax;

    printf("Your Tax Income: %d",taxincome);
}
else if (income>=750 && income<2250){
    printf("\033[0;32m- Tax Bracket 2 -\033[0m\n");
    printf("750 - 2249\n");

    tax = income * .02 + 7.50;
    taxincome = income - tax;

    printf("Your Tax Income: %d",taxincome);
}
else if (income>=2250 && income<3750){
    printf("\033[0;32m- Tax Bracket 3 -\033[0m\n");
    printf("2250 - 3749\n");

    tax = income * .03 + 37.50;
    taxincome = income - tax;

    printf("Your Tax Income: %d",taxincome);
}
else if (income>=3750 && income<5250){
    printf("\033[0;32m- Tax Bracket 4 -\033[0m\n");
    printf("3750 - 5249\n");

    tax = income * .04 + 82.50;
    taxincome = income - tax;

    printf("Your Tax Income: %d",taxincome);
}
else if (income>=5250 && income<7000){
    printf("\033[0;32m- Tax Bracket 5 -\033[0m\n");
    printf("5250 - 6999\n");

    tax = income * .05 + 142.50;
    taxincome = income - tax;

    printf("Your Tax Income: %d",taxincome);
}
else if (income>=7000){
    printf("\033[0;32m- Tax Bracket 6 -\033[0m\n");
    printf("7000+\n");

    tax = income * .06 + 230;
    taxincome = income - tax;

    printf("Your Tax Income: %d",taxincome);
}
else {
    printf("\033[0;31mInvalid Input!\033[0m");}
}

