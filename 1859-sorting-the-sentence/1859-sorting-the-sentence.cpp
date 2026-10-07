class Solution {
public:
    string sortSentence(string s) {
        string ans = "";

        for(int i = 1 ; i <= 9 ; i++){
            string temp = "";
            if(ans.length() == s.length()) break;
            for(int j = 0 ; j < s.length() ; j++){
                temp = temp + s[j];
                if(s[j] == ' '){
                    temp = "";
                }
                else if(s[j] == i + '0'){
                   temp = temp.substr(0,temp.size()-1);
                   if(ans.length() > 0)
                            ans += " ";
                    ans = ans + temp;
                    break;
                }
            }
        }
        return ans;
    }
};