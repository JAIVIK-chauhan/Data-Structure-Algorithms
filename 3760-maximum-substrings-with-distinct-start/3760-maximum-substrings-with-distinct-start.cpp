class Solution {
public:
    int maxDistinct(string s) {
        unordered_set<char> st;
        int count = 0;

        for(int i = 0 ; i < s.length() ; i++){
            st.insert(s[i]);
        }
        return st.size();
    }
};