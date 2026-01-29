//Chapter 9: Functions
//Defining and Calling Functions
//• Functions have to be "defined," and to use them, we have to "call" them.
//Function cannot return arrays
//C99 omitting the return type is illegal

//after function name comes list of parameters.
//parameters separated by commas.
//if function has no parameters the word void should appear between the parenthesis

#include <stdio.h>

double average(double a, double b){
 double avg; //declaration
 avg=(a+b)/2;
  //return avg;
}



int main(void){
    double i = average(50,46);
    printf("the average of 50 and 46 is %lf",i);
}

