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
    int averageOfSubtree(TreeNode* root) {
        int c = 0;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            int sum = 0;
            int count = 0;
            queue<TreeNode*> que;
            que.push(node);

            while(!que.empty()){
                count++;
                TreeNode* n = que.front();
                que.pop();

                sum = sum + n->val;
                if(n->left) que.push(n->left);
                if(n->right) que.push(n->right);
            }
            if((sum/count) == node->val) c++;
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        return c;
    }
};