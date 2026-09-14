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
    int diff = INT_MIN;
    void find(TreeNode* root, int maxi , int min){
        if(root == NULL) return;

        if(root->val < min) min = root->val;
        if(root->val > maxi) maxi = root->val;
        diff = max(diff,maxi - min);

        find(root->left,maxi,min);
        find(root->right,maxi,min);
    }
    int maxAncestorDiff(TreeNode* root) {
        int ans = 0;
        int maxi = INT_MIN;
        int min = INT_MAX;
        find(root,maxi,min);
        return diff;
    }
};