#include <stdio.h>

void generateSubsets(int* nums, int index, int* currentSubset, int* subsetSize, int n) {
    if (index == n) {
        // Print the current subset
        printf("[");
        for (int i = 0; i < *subsetSize; i++) {
            if (i > 0) {
                printf(", ");
            }
            printf("%d", currentSubset[i]);
        }
        printf("]\n");
        return;
    }

    // Include the current element in the subset
    currentSubset[(*subsetSize)++] = nums[index];
    generateSubsets(nums, index + 1, currentSubset, subsetSize, n);

    // Exclude the current element from the subset
    (*subsetSize)--;
    generateSubsets(nums, index + 1, currentSubset, subsetSize, n);
}

int main() {
    int input_array[] = {1, 2, 3};
    int n = sizeof(input_array) / sizeof(input_array[0]);
    int currentSubset[n];
    int subsetSize = 0;

    generateSubsets(input_array, 0, currentSubset, &subsetSize, n);

    return 0;
}
