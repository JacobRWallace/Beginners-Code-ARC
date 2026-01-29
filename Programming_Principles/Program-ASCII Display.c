#include<stdio.h>

int main() {

    int i=0;
    printf("\033[1;35mASCII Values and Equivalent Characters:\033[0m\n");
    for (i = 0; i < 255; i++) {
        printf("ASCII Value:%d \033[0;32mCharacter ID:'%c'\033[0m \n\n",i,(char)i);
        usleep(5000);
    }
    return 0;
}
