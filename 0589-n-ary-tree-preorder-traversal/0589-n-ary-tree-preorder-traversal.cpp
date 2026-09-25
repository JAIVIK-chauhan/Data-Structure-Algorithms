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
    void traverse(vector<int>& arr, Node* root, stack<Node*>& st) {
        while (!st.empty()) {
            Node* node = st.top();
            st.pop();
            arr.push_back(node->val);
            int size = node->children.size();

            for (int i = size - 1; i >= 0; i--) {
                st.push(node->children[i]);
            }
        }
    }
    vector<int> preorder(Node* root) {
        vector<int> arr;
        if(root == NULL) return arr;
        stack<Node*> st;
        st.push(root);
        traverse(arr, root, st);
        return arr;
    }
};