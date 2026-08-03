class Solution {
public:
    bool isPowerOfTwo(int n) {
        int c = 0;
        while(n){
            int dig = n % 2;
            n = n / 2;
            if(dig == 1) c++;
        }

        if(c == 1) return true;
        else return false;
    }
};