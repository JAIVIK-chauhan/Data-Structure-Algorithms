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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;

        queue<TreeNode*> q;
        q.push(root);
        double sum = 0;
        int c = 0;

        while(!q.empty()){
            sum = 0;
            c = 0;
            int size = q.size();

            for(int i = 0 ; i < size ; i++){
                c++;
                TreeNode* node = q.front();
                q.pop();
                sum = sum + node->val;

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            double avg = sum / c;
            ans.push_back(avg);
        }
        return ans;
    }
};