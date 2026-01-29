#include <stdio.h>

int main() {
    int *ptr;

    // Allocate memory for an integer dynamically
    ptr = (int *)malloc(sizeof(int));

    // Check if memory allocation is successful
    if (ptr != NULL) {

        // Use the dynamically allocated memory
        *ptr = 30;
        printf("Value in dynamically allocated memory: %d\n", *ptr);

        // Don't forget to free the allocated memory when done
        free(ptr);
}   else {
        printf("Memory allocation failed.\n");
}

    printf("after free: %d\n",*ptr);

    return 0;
}
