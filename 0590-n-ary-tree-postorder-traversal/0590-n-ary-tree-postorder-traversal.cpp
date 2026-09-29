/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void traverse(Node* root, vector<int>& ans, stack<Node*>& st){
        while(!st.empty()){
            Node* node = st.top();
            st.pop();
            ans.insert(ans.begin(),node->val);
            int size = node->children.size();
            for(int i = 0 ; i <size  ; i++){
                st.push(node->children[i]);
            }
        }
       
    }
    vector<int> postorder(Node* root) {
        vector<int> ans;
        if(root == NULL) return ans;
        stack<Node*> st;
        st.push(root);
        traverse(root,ans,st);
        return ans;
    }
};