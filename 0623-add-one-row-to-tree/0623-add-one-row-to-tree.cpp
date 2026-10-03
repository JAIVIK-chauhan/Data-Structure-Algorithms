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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (root == NULL)
            return root;

        if (depth == 1) {
            TreeNode* node = new TreeNode(val);
            node->left = root;
            root = node;
            return root;
        }

        int dep = 1;
        queue<TreeNode*> q;
        q.push(root);

        while (dep != depth - 1) {
            int sz = q.size();

            for (int i = 0; i < sz; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            dep++;
        }

        while (!q.empty()) {
            TreeNode* node1 = new TreeNode(val);
            TreeNode* node2 = new TreeNode(val);
            TreeNode* curr = q.front();
            q.pop();

            TreeNode* lt = curr->left;
            TreeNode* rt = curr->right;

            curr->left = node1;
            curr->right = node2;

            node1->left = lt;
            node2->right = rt;
        }

        return root;
    }
};