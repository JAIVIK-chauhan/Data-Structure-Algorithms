class Solution {
public:
    string largestEven(string s) {
        int i = s.length() - 1;
        if (s[i] == '2')
            return s;
        while (i >= 0 && s[i] == '1') {
            s.pop_back();
            i--;
        }
        return s;
    }
};