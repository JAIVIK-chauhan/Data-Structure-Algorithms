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

    void insert(TreeNode*& root , TreeNode* node){
        if(root == NULL){
            root = node;
            return;
        }
        if(root->val < node->val){
            insert(root->right,node);
        }
        else insert(root->left,node);
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* node = new TreeNode(val);
        
        insert(root,node);
        return root;
    }
};