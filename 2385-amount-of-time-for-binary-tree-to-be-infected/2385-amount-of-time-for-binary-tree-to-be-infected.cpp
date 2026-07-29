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
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*> parent;
        queue<TreeNode*> q;
        TreeNode* st = nullptr;
        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node->val == start) st = node;

            if(node->left){
                parent[node->left] = node;
                q.push(node->left);
            }
            if(node->right){
                parent[node->right] = node;
                q.push(node->right);
            }
        }

        unordered_map<TreeNode*,bool> visited;
        queue<TreeNode*> que;
        int min = 0;
        que.push(st);
        visited[st] = true;

        while(!que.empty()){
            
            int size = que.size();

            for(int i = 0 ; i < size ; i++){
                TreeNode* node = que.front();
                que.pop();

                if(node->left && !visited[node->left]){
                    visited[node->left] = true;
                    que.push(node->left);
                }
                if(node->right && !visited[node->right]){
                    visited[node->right] = true;
                    que.push(node->right);
                }
                if(parent[node] && !visited[parent[node]]){
                    visited[parent[node]] = true;
                    que.push(parent[node]);
                }
            }
            min++;
        }
        return min-1;
    }
};