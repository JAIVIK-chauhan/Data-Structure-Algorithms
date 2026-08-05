class Solution {
public:
    int balancedStringSplit(string s) {
        int ans = 0;

        int f = 0;

        for(int i = 0 ; i < s.length() ; i++){
            if(s[i] == 'L') f++;
            else f--;

            if(f == 0) ans++;
        }
        return ans;
    }
};