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
    TreeNode* build(vector<int> arr, int& idx , int bound){
        if(idx >= arr.size() || arr[idx] > bound) return NULL;
        TreeNode* root = new TreeNode(arr[idx]);
        root->left = build(arr,++idx,root->val);
        root->right = build(arr,idx,bound);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int idx = 0;
        return build(preorder,idx,INT_MAX);
    }
};