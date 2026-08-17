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
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* node = head;
        stack<int> st;

        while(fast != NULL && fast -> next != NULL){
            fast = fast -> next -> next;
            slow = slow -> next;
        }

        while(slow != NULL){
            st.push(slow->val);
            slow = slow -> next;
        }

        int ans = 0;

        while(!st.empty()){
            int n1 = st.top();
            st.pop();
            int n2 = node->val;

            ans = max(ans,n1+n2);
            node = node -> next;
        }
        return ans;
    }
};