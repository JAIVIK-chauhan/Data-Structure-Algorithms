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
    int findSecondMinimumValue(TreeNode* root) {
        int min1 = INT_MAX;
        int min2 = INT_MAX;
        int fg = 0;

        if(root == NULL) return -1;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            if(node->val < min1){
                min2 = min1;
                min1 = node->val;
            }
            else if(node->val <= min2 && node->val != min1){
                min2 = node->val;
                fg = 1;
            }
            
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        return fg == 0 ? -1 : min2;
    }
};