/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    bool ans = true;
    void check(TreeNode* leftt, TreeNode* rightt){
        if(leftt == NULL && rightt == NULL) return;
        if(leftt == NULL || rightt == NULL){
            ans = false;
            return;
        }

        if(leftt->val != rightt->val){
            ans = false;
            return;
        }

        check(leftt -> left,rightt -> right);
        check(leftt -> right,rightt -> left);
        
    }

    bool isSymmetric(TreeNode* root) {
       if(root == NULL) return true;

       check(root->left,root->right); 
       return ans;
    }
};