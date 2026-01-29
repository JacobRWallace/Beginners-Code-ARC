#include<stdio.h>
#include<stdlib.h>

//Advanced Uses of Pointers

//Concatenate - Link (things) together in a chain or series.
//IN CODING: String concatenation is the operation of joining character strings end-to-end. For example, the concatenation of "snow" and "ball" is "snowball".

//Allocate - Distribute (resources or duties) for a particular purpose.
//IN CODING: Allocation is the process of requesting access to a data set. If you allocate a data set that exists, the system allows you to open the data set. If you allocate a data set that does not exist, the system creates space for it on an available device and allows you to open that space.

//Dynamic Storage Allocation
//<stdlib.h> header declares three memory allocation fucntions
//malloc - Allocates a block of memory but doesn't initialize it.

//malloc function is used to assign a specified amount of memory for an array to be created. It also returns a pointer to the space allocated in memory using this function.

//calloc - Allocates a block of memory and clears it.
//realloc - Resizes a previously allocated block of memory.

//if memory allocation can't be found will return null pointer.

//Example: void *malloc(size_t size); //size_t is the size that is needed to search for

//concat - if given two strings it will return combined strings in one.

char *concat(const char *a, const char *b){ //const says it does not change
    char *result; //defining pointer should be a string
    result=malloc(strlen(a)+strlen(b)+1); //+1 adds a null character to string

    if(result==NULL){
        printf("Error malloc failed to allocate memory");

        exit(EXIT_FAILURE); //almost the same as return but doesnt show error message
    }
    strcpy(result,a); //copies str a into result
    strcat(result,b); //combines b and result in a string
}

a = malloc(n * sizeof(string))//sizeof pulls bytes of string. Multiplying by n will give you the string length of bytes.

void main(){
 char *a, *b, *p;
  a="abcdef";
  b="ghij";
  p=concat(a,b);

  printf("%s",p);

  free(p);//this prevents a memory/data leak (without this pc will run slow)
}
