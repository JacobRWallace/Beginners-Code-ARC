#include <stdio.h>
#define NODE_COUNT 6

struct Node {
    int value;
    struct Node* next;
};

void main(){

    struct Node nodes[NODE_COUNT]; 

    for (int i = 0; i < NODE_COUNT; i++)
    {
        nodes[i].value = (i + 1) * 10;

        if (i == NODE_COUNT - 1)
            nodes[i].next = NULL; //last node points to null
        else
            nodes[i].next = &nodes[i+1]; //point to next node
    }

    struct Node *current = &nodes[0]; // Have to make a struct type pointer,(its like int, a type of data type) cant do void. "struct Node*" is like a variable type as if i was calling "int* current"

    while(current != NULL){
        printf("Value: %d\n", current->value);
        current = current->next;    //point to next node
    }

}