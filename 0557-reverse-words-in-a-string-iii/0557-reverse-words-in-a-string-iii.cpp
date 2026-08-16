class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        int j = 0;

        while(j < s.length()){
            string temp = " ";

            while(j < s.length() && s[j] != ' '){
                temp = temp + s[j];
                j++;
            }
            reverse(temp.begin(),temp.end());
            ans = ans + temp;
            j++;
        }
        ans.pop_back();
        return ans;
    }
};