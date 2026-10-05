class Solution {
public:
    bool validPalindrome(string s) {
        int i = 0;
        int j = s.length() - 1;

        while (i <= j) {
            if (s[i] == s[j]) {
                i++;
                j--;
            }
            else {
                int k = i+1;
                int z = j;

                int f1 = 1;
                int f2 = 1;
                while (k <= z) {
                    if (s[k] == s[z]) {
                        k++;
                        z--;
                    } else {
                        f1 = 0;
                        break;
                    }
                }
                k = i;
                z = j-1;

                while (k <= z) {
                    if (s[k] == s[z]) {
                        k++;
                        z--;
                    } else {
                        f2 = 0;
                        break;
                    }
                }
                return f1 || f2;
            }
        }
        return true;
    }
};