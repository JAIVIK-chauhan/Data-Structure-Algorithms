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
    bool isLeaf(TreeNode* node) {
        if (node->left || node->right)
            return false;
        else
            return true;
    }

    int sumOfLeftLeaves(TreeNode* root) {
        queue<TreeNode*> q;
        int sum = 0;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node->left) {
                if (isLeaf(node->left))
                    sum = sum + node->left->val;
                else
                    q.push(node->left);
            }
            if (node->right) {
                if (!isLeaf(node->right))
                    q.push(node->right);
            }
        }
        return sum;
    }
};