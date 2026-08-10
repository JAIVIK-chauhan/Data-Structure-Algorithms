class Solution {
public:
    bool isPowerOfFour(int n) {
        long long i = 1;

        while(i <= n){
            if(i == n) return true;
            else i = i * 4;
        }
        return false;
    }
};