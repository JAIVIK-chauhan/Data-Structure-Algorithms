/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {

    struct ListNode *newNode = NULL;
    struct ListNode *head = NULL;
    struct ListNode *tail = NULL;

    struct ListNode * temp1 = l1;
    struct ListNode * temp2 = l2;

    int sum = 0;
    int carry = 0;
    int x = 0;
    int y = 0;

    while(temp1 != NULL || temp2 != NULL){

        x = (temp1 != NULL)? temp1 -> val : 0;
        y = (temp2 != NULL)? temp2 -> val : 0;

        sum = x + y + carry;
        carry = sum/10;

        newNode = (struct ListNode *) malloc(sizeof(struct ListNode));
        newNode -> val = sum % 10;
        newNode -> next = NULL;

        if(head == NULL){
            head = newNode;
            tail = newNode;
        }
        else{
            tail -> next = newNode;
            tail = newNode;
        }

        if(temp1 != NULL) 
            temp1 = temp1 -> next;
        if(temp2 != NULL)
            temp2 = temp2 -> next;
       
    }

    if(carry > 0){
        newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
        newNode -> val = carry;
        newNode -> next = NULL;
        tail -> next = newNode;
    }

    return head;
}