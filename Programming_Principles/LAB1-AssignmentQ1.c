
#include<stdio.h>

int main() {

    int yearinput;
    printf("Enter a year after 1990:");
    scanf("%d",&yearinput);
    int yearcalc = yearinput - 1990;
    float population = 52.966 + 2.184 * yearcalc;

    //int temp=2015-1990;
    //printf("%d",temp);

    printf("Predicted Gotham City population for %d (in thousands):",yearinput);
    printf("%0.3f",population);
}
