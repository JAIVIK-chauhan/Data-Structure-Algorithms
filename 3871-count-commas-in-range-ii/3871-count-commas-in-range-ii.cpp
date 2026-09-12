class Solution {
public:
    long long countCommas(long long n) {
        long long base = 1000;
        long long ans = 0;

        while(base <= n){
            ans = ans + n - base + 1;
            base = base * 1000;
        }
        return ans;
    }
};