/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode *pn;

void helper (struct TreeNode *root){
    if(root == NULL)
        return;
    
    helper(root->right);
    helper(root->left);

    root->left = NULL;
    root -> right = pn;
    pn = root;
}

void flatten(struct TreeNode* root) {
    pn = NULL; 
    helper(root);
    
       
    
}