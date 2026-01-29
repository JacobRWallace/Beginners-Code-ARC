#include <stdio.h>

toPower(int a,int b){
    if(b==0){
        return 1;
    }
    for(int i=1; i<b ; i++){
        a *= a;
    }
    return a;
}