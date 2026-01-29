// "\033[0;31m" = RED
// "\033[1;32m" = GREEN
// "\033[0;33m" = YELLOW
// "\033[1;35m" = PINK (REALLY LIGHT PURPLE)
// "\033[0;36m" = CYAN

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void subgen(int* elements, int index, int* subset, int* size, int n) {
    if (index == n) {
        printf("[");
        for (int i = 0; i < *size; i++) {
            if (i > 0) {
                printf(", ");
            }
            printf("%d", subset[i]);
        }
        printf("]\n");
        return;
    }

    subset[(*size)++] = elements[index];
    subgen(elements, index + 1, subset, size, n);

    (*size)--;//decrease pointer
    subgen(elements, index + 1, subset, size, n);
}

int main() {
    int myArray[] = {1, 2, 3};
    int n = sizeof(myArray) / sizeof(myArray[0]);//find the length of array or number of elements
    int size = 0;
    int subset[n];

    //printf("%d\n",n);
    subgen(myArray, 0, subset, &size, n);

    return 0;
}
