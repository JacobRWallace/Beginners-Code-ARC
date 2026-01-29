/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

 //gets lenght of linked list by making temp structure to iterate through
int getLength(struct ListNode* linkedList){
    int len = 0;
    struct ListNode *curr = linkedList;
    while (curr != NULL){
        len++;
        curr = curr->next;}
    return len;
}

int getValues(struct ListNode* linkedList, int size){
    int values[size], output = 0;
    struct ListNode *curr = linkedList;

    //loop through, store each val in array
    //printf("values = ");
    for (int i = 0; i<size && curr != NULL; i++){
        values[i] = curr->val;
        curr = curr->next;
        //printf("%d ", values[i]);
    }

    //reverse build array and output integer
    //printf("\n");
    for (int i = size; i>0; i--){
        output = output*10;
        output += values[i-1];
        //printf("output = %d\n", output);
    }
    return output;
}

void intToList(int num) { //unfinished
    num % 10
    for(int i; i>size)
}
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    
    /*  TODO
        1. get length of both lists
        2. for loop to store values of each linked lists
        3. reverse stored values
        4. add and return
    */

    //1
    int len1 = getLength(l1);
    int len2 = getLength(l2);
    printf("l1 len = %d, l2 len = %d\n", len1, len2);

    //2
    int val1 = getValues(l1, len1);
    int val2 = getValues(l2, len2);
    printf("l1 val = %d, l2 val = %d\n", val1, val2);

    int result = val1 + val2;
    return intToList(result); //unifinished. have to convert back to array and return in ListNode struct form after reversing array after converting int number to array. Basically process but backwards lol(hell nah)
}