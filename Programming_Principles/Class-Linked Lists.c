#include <stdio.h>

/*
Linked Lists:
linked list is a consists of a chain of structures(called nodes), with each structure containing a pointer to the next node in the chain.
the last structure's(node's) pointer is a null pointer.
link lists are trees and are used a lot.
*/

/*
Creating a Node:
1. allocate memory for the node.
struct node *new_node;

new_node = malloc(sizeof(struct node));

2. store data in the node.
(*new_node).value = 10;
or
new_node->value = 10;

3. insert the node into the list.
    first step:
new_node->next = first;
    second step:
first = new_node;
*/

void main(){

struct node{
 int value; /*data stored in the node */
 struct node *next; /* pointer to the next node */
};



}
