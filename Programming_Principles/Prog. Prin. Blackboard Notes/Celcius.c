/* Converts  Fahrenheit to Celcius */
 #include<stdio.h>
 #define FREEZIN_POINT 32.00f
 #define SCALING_FACTOR 5/9


 int main(void){
  float f, celsius,Fahrenheit;
  // Read an input to fahrenheit
  printf(" Give an input for fahrenheit temperature: ");
  scanf("%f",&fahrenheit);
  /* Converting Fahrenheit to Celcius */

  celsius=(fahrenheit-FREEZIN_POINT)*SCALING_FACTOR;
  // Printing the Celcius equivalent

  printf("Celcius equivalent: %0.2f\n",celsius);
  return 0;

 }

