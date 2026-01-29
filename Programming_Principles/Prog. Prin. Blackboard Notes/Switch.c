# include<stdio.h>
int main(){
 int grade;
 scanf("%d",&grade);
switch(grade) {
   default: printf("Illegal Grade");
       break;

  case 3: printf("\nGood");
         break;
  case 2: printf("Okay");
         break;

  case 1: printf("Bad");
         break;
  case 0: printf("Failing");
         break;
  case 4: printf("Excellent");
          printf("\nVery good boy");
          printf("\nGood work");



} /*
switch(grade) {
  case 4:
  case 4:
  case 2:
  case 1: printf("Pass");
         break;
  case 0: printf("Failing");
         break;
   default: printf("Illegal Grade");
       break;


}*/

printf("\nFinished switch statement ");

}