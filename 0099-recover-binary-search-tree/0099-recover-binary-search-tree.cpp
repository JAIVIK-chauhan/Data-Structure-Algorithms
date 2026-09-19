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
    void in(TreeNode* root, vector<int>& v){
        if(root == NULL) return;

        in(root->left,v);
        v.push_back(root->val);
        in(root->right,v);
    }
    void recoverTree(TreeNode* root) {
        int fg1 = 0;
        int fg2 = 0;
        vector<int> v;
        in(root,v);
        vector<int> arr(v.begin(),v.end());
        sort(arr.begin(),arr.end());
        int l=-1,r=-1;
        int i = 0;
        while(i < arr.size()){
            if(v[i] != arr[i]){
                if(l == -1) l = arr[i];
                else{
                    r = arr[i];
                    break;
                } 
            }
            i++;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            
            if(node->val == l){
                fg1 = 1;
                node->val = r;
            } 
            else if(node->val == r){
                node->val = l;
                fg2 = 1;
            }

            if(fg1 == 1 && fg2 == 1) break;

            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
    }
};