#include <stdio.h>
#include <stdlib.h>

typedef struct listnode {
    int data;
    struct listnode *next;
} node;

node* findMiddle(node* head) {
    if (head == NULL) {
        return NULL;
    }

    node* slow = head;
    node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

void insertNode(node** head, int data) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void printList(node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    node* head = NULL;
    int n, data;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        insertNode(&head, data);
    }

    printf("Linked List: ");
    printList(head);

    node* middle = findMiddle(head);

    if (middle != NULL) {
        printf("Middle Node: %d\n", middle->data);
    } else {
        printf("List is empty.\n");
    }

    return 0;
}

//The time complexity used was O(n) because of the use of slow and fast pointers.
