/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev1 = head;
        ListNode* prev2 = head;
        ListNode* prev = head;
        int fg = 0;

        while(curr != NULL && curr -> next != NULL){
            ListNode* temp = curr -> next;
            curr -> next = temp -> next;
            temp -> next = curr;

            if(fg == 1){
                prev -> next = temp;   
                prev = curr;
            }
            curr = curr -> next;

            if(fg == 0){
                fg = 1;
                head = temp;
            }
        }
        return head;
    }
};