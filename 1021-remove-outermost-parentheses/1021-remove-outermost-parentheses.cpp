class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        string res = "";
        stack<char> st;

        int i = 0;
        st.push(s[i]);
        ans = ans + s[i];
        i++;

        while(i < s.length()){

            if(s[i] == '('){
                st.push('(');
                ans = ans + '(';
            } 
            else if(st.top() == '(') 
            {
                st.pop();
                ans = ans + ')';
            }
            else{
                st.push(')');
                ans = ans + ')';
            }

            if(st.empty()){
                ans = ans.substr(1,ans.size()-2);
                res = res + ans;
                ans = "";
            }
            i++;
        }
        return res;
    }
};