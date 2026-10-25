class Solution {
public:
    string longestNiceSubstring(string s) {
        string str = "";
        string ans = "";
        for(int i = 0 ; i < s.length() ; i++){
            unordered_set<char> st;
            str = "";
            for(int j = i ; j < s.length() ; j++){
                str = str + s[j];
                st.insert(s[j]);

                bool nice = true;

                for(int k = 0 ; k < str.length() ; k++){
                    if(islower(str[k])){
                        if(!st.contains(toupper(str[k]))){
                            nice = false;
                            break;
                        }
                    }
                    if(isupper(str[k])){
                        if(!st.contains(tolower(str[k]))){
                            nice = false;
                            break;
                        }
                    }
                }
                    if(nice && str.length() > ans.length()) ans = str;
            }
        }
       return ans;
    }
};
