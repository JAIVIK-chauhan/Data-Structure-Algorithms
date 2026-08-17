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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ans;
        queue<TreeNode*> q;
        if(root1 != NULL) q.push(root1);

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            ans.push_back(node->val);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        queue<TreeNode*> q1;
        if(root2 != NULL)q1.push(root2);

        while(!q1.empty()){
            TreeNode* node = q1.front();
            q1.pop();

            ans.push_back(node->val);
            if(node->left) q1.push(node->left);
            if(node->right) q1.push(node->right);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};