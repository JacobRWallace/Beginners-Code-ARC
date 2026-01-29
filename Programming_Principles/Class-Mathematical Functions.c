#include<stdio.h>

static i;

int gcd(int m, int n){
    int ans;
    if (m%n==0)
        ans = n;
    else
        ans = gcd(n,m%n);
        i++;
        return ans;
}


main(void) {

int m,n;
printf("Enter value 1: \033[0;33m");
scanf("%d",&n);
printf("\033[0mEnter value 2: \033[0;33m");
scanf("%d",&m);

printf("\033[0mThe \033[0;33mGCD\033[0m of \033[0;33m%d\033[0m and \033[0;33m%d\033[0m is \033[0;32m%d\033[0m",n,m,gcd(m,n));
printf("\n\033[0;36mi Value: %d\033[0m",i);
/*
if (m%n==0) {
    printf("GCD: %d",n);
    return n;
    }
else {
    printf("GCD: %d",m);
    return m;
        }
*/
}
