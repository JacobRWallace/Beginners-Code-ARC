#include<stdio.h>

int* findMax(int arr[], int size){ //int* returns a pointer (expects it to at least)
    int *maxElement = &arr[0];

    for (int i = 1; i < size; i++){
        if (arr[i] > *maxElement){
            maxElement = &arr[i];}
    }
    return maxElement;
}

int multiplyRecursive(int arr[], int size) {
    return arr[size - 1] * multiplyRecursive(arr, size - 1);
}

void circularShift(int arr[], int size, int shiftBy) {

    int *ptr = (int *)malloc(shiftBy * sizeof(int));

    // copy the 4 elements being shifted into a seperate temporary array
    for (int i = size - shiftBy, j = 0; i < size; i++, j++) {
        ptr[j] = arr[i];}

    // shift elements to the right.
    for (int i = size - shiftBy - 1; i >= 0; i--) {
        arr[i + shiftBy] = arr[i];}

    // Put temporary elements back into original array
    for (int i = 0; i < shiftBy; i++) {
        arr[i] = ptr[i];}

    free(ptr);
}

int main(){
    int *maxElementPtr, result;//print these values

    int Myarray[6]={1,3,4,20,100,12};
    int size = sizeof(Myarray) / sizeof(Myarray[0]);
    char choice;

    printf("[F] = Find Max\n");
    printf("[M] = Multiply Recursively\n");
    printf("[C] = Circular Shift\n");

while(1){ //loop to enter options
    printf("Enter Option: ");
    scanf(" %c", &choice);

    switch (choice) {
    case 'F':
    case 'f':
        maxElementPtr = findMax(Myarray, size);
        printf("Max Value in Array: %d\n",*maxElementPtr);
    break;

    case 'M':
    case 'm':
        result = findMax(Myarray,size);
        printf("Multiplication Result: %d\n",result);
    break;

    case 'C':
    case 'c':
        printf("Original Array:\n");
        for (int i = 0; i < size; i++) {
            printf("%d ", Myarray[i]);
        }

        circularShift(Myarray, size, 2);

        printf("\n2 Position Circular Shifted Array:\n");
        for (int i = 0; i < size; i++) {
            printf("%d ", Myarray[i]);
        }
        printf("\n");
    break;

    default:
        printf("Error: Invalid Input!");
}//switch
}//while
}//main
