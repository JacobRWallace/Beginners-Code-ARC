#include <stdio.h>

int main() {
    int cityApop, cityBpop;
    float cityAgrate, cityBgrate;

    printf("Enter Population of City A: ");
    scanf("%d", &cityApop);
    printf("Enter Growth Rate of City A: ");
    scanf("%f", &cityAgrate);
    printf("Enter Population of City B: ");
    scanf("%d", &cityBpop);
    printf("Enter Growth Rate of City B: ");
    scanf("%f", &cityBgrate);

    int years = 0;

    while (cityApop < cityBpop) {
        cityApop += cityApop * cityAgrate;
        cityBpop += cityBpop * cityBgrate;
        years++;
    }

    printf("In %d years, City A will have a population of %d and City B will have a population of %d.\n", years, cityApop, cityBpop);
}
