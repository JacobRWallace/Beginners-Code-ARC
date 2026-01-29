#include <stdio.h>
#include <stdlib.h> //call malloc; malloc function creates memory.

typedef struct node{
    int data;
    struct node *next;
}node;

node * createLinkedList(int n);
void displayList();

int main(){

    //https://www.youtube.com/watch?v=7Fz7JSvlr9g

    int n = 0;
    int input;

    node * HEAD = NULL;
    printf("Enter # nodes: ");
    scanf("%d", &n);
    HEAD = createLinkedList(n);

    displayList(HEAD);
    void displayList(node * head);

    return 0;
}

//function to create linked list.
node * createLinkedList(int n){ //node * returns the address of the first node.
    int i = 0;
    node *head = NULL;
    node *temp = NULL;
    node *p = NULL;

    //Create individual isolated node
    for(i=0;i<n;i++){
        temp = (node *)malloc(sizeof(struct node));
        printf("Enter data for Node #%d: ",i+1);
        scanf("%d",&(temp->data));
        temp->next=NULL;

        if(head == NULL) //if list is currently empty, then make temp as first node.
            head = temp;
        else{
            p = head;
            while(p->next != NULL)
                p = p->next;
            p->next = temp;
        }
    }

    return head;
}

//function to print list.
void displayList(node * head){

    node * p = head;
    
    while(p != NULL){
        printf("\t%d->",p->data);
        p = p->next;
    }
}