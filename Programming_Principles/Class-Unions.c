#include<stdio.h>
#include<string.h>

//UNION NOTES:
//members of a union are accessed in the same way as members of a structure

void main(){



//strcpy test
char x[] = "test1";
char n[] = "override";
strcpy(x,n);
printf("x: %s\n",x);
printf("n: %s\n",n);


}
