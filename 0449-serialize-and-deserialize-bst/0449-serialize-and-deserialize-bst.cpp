/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == NULL)
            return "";

        string s = "";
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node == NULL)
               s += "#,";
            else
                s += to_string(node->val) + ",";

            if (node != NULL) {
                q.push(node->left);
                q.push(node->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.length() == 0)
            return NULL;

        vector<string> values;
        string temp = "";

        for (char ch : data) {
            if (ch == ',') {
                values.push_back(temp);
                temp = "";
            } else
                temp = temp + ch;
        }
        values.push_back(temp);

        queue<TreeNode*> q;
        TreeNode* root = new TreeNode(stoi(values[0]));
        q.push(root);
        int i = 1;

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (values[i] != "#") {
                node->left = new TreeNode(stoi(values[i]));
                q.push(node->left);
            }
            i++;

            if (i < values.size() && values[i] != "#") {
                node->right = new TreeNode(stoi(values[i]));
                q.push(node->right);
            }
            i++;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;