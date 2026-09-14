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
    int ans = -1;
    void trace(TreeNode* root , vector<int>& arr , int k){
        if(root == NULL) return;

        trace(root->left,arr,k);
        arr.push_back(root->val);
        if(arr.size()==k){
            ans = root->val;
            return;
        }
        trace(root->right,arr,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> arr;
        trace(root,arr,k);
        return ans;
    }
};