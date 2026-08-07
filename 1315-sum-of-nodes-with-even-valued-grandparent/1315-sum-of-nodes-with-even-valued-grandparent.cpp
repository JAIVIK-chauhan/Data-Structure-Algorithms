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
    int sumEvenGrandparent(TreeNode* root) {
        unordered_map<TreeNode*,TreeNode*> parent;
        queue<TreeNode*> q;
        q.push(root);
        int sum = 0;

        while(!q.empty()){
            int size = q.size();

            for(int i = 0 ; i < size ; i++){
                TreeNode* node = q.front();
                q.pop();

                if(node->left){
                    q.push(node->left);
                    parent[node->left] = node;
                }
                if(node->right){
                    q.push(node->right);
                    parent[node->right] = node;
                }
            }   
        }

        for(auto it : parent){
            TreeNode* node = it.first;
            TreeNode* prnt = it.second;
            TreeNode* grandParent = NULL;

            if(parent.find(prnt) != parent.end())
                grandParent = parent[prnt];
            
            if(grandParent != NULL)
                if(grandParent -> val % 2 == 0) sum = sum + node -> val;
        }
        return sum;
    }
};