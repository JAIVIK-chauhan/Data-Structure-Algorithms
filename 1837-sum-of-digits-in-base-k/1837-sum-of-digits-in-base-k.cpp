class Solution {
public:
    int sumBase(int n, int k) {
        int num = 0;
        int i = 1;
        if(k != 10){
            while(n){
                int dig = n % k;
                n = n / k;
                num = (dig*i) + num;
                i = i * 10;
            }
        }else num = n;
        
        int sum = 0;
        while(num){
            int dig = num % 10;
            num = num / 10;
            sum = sum + dig;
        }
        return sum;
    }
};