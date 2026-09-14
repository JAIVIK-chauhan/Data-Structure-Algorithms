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
     void traverse(TreeNode* root,int& sum){
        if(root == NULL) return;

        traverse(root->left,sum);
        sum = sum + root->val;
        traverse(root->right,sum); 
    }

    void gst(TreeNode* root, int& sum){
        if(root == NULL) return;

        gst(root->left,sum);
        sum = sum - root->val;
        root->val = root->val + sum;
        gst(root->right,sum);
    }

    TreeNode* convertBST(TreeNode* root) {
       int sum = 0;
       traverse(root,sum);
       gst(root,sum);    
       return root;          
    }
};