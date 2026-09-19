/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* small = nullptr;
    TreeNode* parentOfSmall = nullptr;
    TreeNode* big = nullptr;
    TreeNode* parentOfBig = nullptr;
    void findr(TreeNode* root, TreeNode* parent) {
        if (root == NULL)
            return;

        if (root->left == NULL) {
            small = root;
            parentOfSmall = parent;
            return;
        }
        findr(root->left, root);
    }
    void findl(TreeNode* root, TreeNode* parent) {
        if (root == NULL)
            return;

        if (root->right == NULL) {
            big = root;
            parentOfBig = parent;
            return;
        }
        findl(root->right, root);
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* node = root;
        TreeNode* parent = NULL;

        while (node != NULL) {
            if (node->val < key) {
                parent = node;
                node = node->right;
            } else if (node->val > key) {
                parent = node;
                node = node->left;
            } else
                break;
        }
        if (node == NULL)
            return root;

        if (node->left == NULL && node->right == NULL) {
            if (parent == NULL)
                return NULL;
            if (parent->left == node)
                parent->left = NULL;
            else
                parent->right = NULL;
            return root;
        } else if (node->right != NULL) {
            findr(node->right, node);
            node->val = small->val;

            if (parentOfSmall->left == small)
                parentOfSmall->left = small->right;
            else
                parentOfSmall->right = small->right;
            return root;
        } else {
            findl(node->left, node);
            node->val = big->val;
            if (parentOfBig->left == big)
                parentOfBig->left = big->left;
            else
                parentOfBig->right = big->left;
            return root;
        }
        return root;
    }
};