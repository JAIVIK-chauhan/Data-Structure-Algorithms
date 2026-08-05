class Solution {
public:
    string stringHash(string s, int k) {
        string ans = "";
        int i = 0;

        while(i < s.length()){
            int sum = 0;
            for(int st = i ; st < i+k ; st++){
                sum = sum + s[st] - 'a';
            }
            int mod = sum % 26;
            ans = ans + char('a'+mod);
            i = i+k;
        }
        return ans;
    }
};