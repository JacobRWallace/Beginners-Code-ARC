#include <stdio.h>

void geeks() //EXAMPLE 1
{
	int var = 10;

	// declare pointer variable
	int* ptr;

	// note that data type of ptr and var must be same
	ptr = &var;

	// assign the address of a variable to a pointer
	printf("Value at ptr = %p \n", ptr);
	printf("Value at var = %d \n", var);
	printf("Value at *ptr = %d \n", *ptr);
    printf("Value at &var = %d \n", &var);
}

// Driver program
int main()
{
	geeks();
	return 0;
} //END OF EXAMPLE 1


int main2() //problem
{
    printf("Problem:\n");
    int *ptr;
    int x;

    ptr = &x;
    *ptr = 0;

    printf("x = %d\n", x);
    printf("*ptr = %d\n", *ptr);

    *ptr += 5;
    printf("x  = %d\n", x);
    printf("*ptr = %d\n", *ptr);

    (*ptr)++;
    printf("x = %d\n", x);
    printf("*ptr = %d\n", *ptr);

    return 0;
}


int main3() //explanation for problem
{
    printf("Explanation:\n");
    int *ptr;  /* Note: the use of * here is not for dereferencing,
                   it is for data type int */
    int x;

    ptr = &x;   /* ptr now points to x (or ptr is equal to address of x) */
    *ptr = 0;   /* set value at ptr to 0 or set x to zero */

    printf("x = %d\n", x);   /* prints x =  0 */
    printf("*ptr = %d\n", *ptr);  /* prints *ptr =  0 */


    *ptr += 5;        /* increment the value at ptr by 5 */
    printf("x  = %d\n", x);  /* prints x = 5 */
    printf("*ptr = %d\n", *ptr); /* prints *ptr =  5 */


    (*ptr)++;         /* increment the value at ptr by 1 */
    printf("x  = %d\n", x);  /* prints x = 6 */
    printf("*ptr = %d\n", *ptr);  /* prints *ptr =  6 */
}
