#include <stdio.h>

#define WIDTH 43
#define HEIGHT 5

const char MAP[HEIGHT][WIDTH] = {
    "          X          X          X          ",
    "          X                     X          ",           
    "                     X          X          ",           
    "          X          X                     ",           
    "          X          X          X          "
};

int main() {
    while (1) {

        for (int i = 0; i < HEIGHT; i++) {
            printf("%s\n", MAP[i]);
        }
    
    
    }
    return 0;
}