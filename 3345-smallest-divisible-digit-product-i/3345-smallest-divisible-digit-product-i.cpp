class Solution {
public:
    int smallestNumber(int n, int t) {
        int ans = 0;

        while(1){
            int mul = 1;
            int num = n;
            while(num){
                int dig = num%10;
                num = num/10;
                mul = mul*dig;
            }
            if(mul%t == 0) return n;
            n++;
        }
        return -1;
    }
};