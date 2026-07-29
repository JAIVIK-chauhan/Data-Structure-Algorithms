/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int count = 0;
void helper(struct TreeNode* root){

    if(root != NULL){
        count++;
        helper(root->left);
        helper(root->right);
    }
}
int countNodes(struct TreeNode* root) {
    count = 0;
    if(root == NULL)
        return 0;
    
    helper(root);
    return count;
}