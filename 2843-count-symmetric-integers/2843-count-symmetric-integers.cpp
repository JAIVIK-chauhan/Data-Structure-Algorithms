class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0;

        while(low <= high){
            int num = low;
            int n = 0;
            int sum = 0;
            int dig = 0;

            while(num){
                n = num % 10;
                num = num / 10;
                dig++;
                sum = sum + n;
            }
            num = low;
            if(dig%2 == 0 && sum%2 == 0){
                int s = sum/2;
                int d = dig/2;
                int t = 0;
                int tsum = 0;
                while(t < d){
                    int dd = num % 10;
                    num = num / 10;
                    tsum = tsum + dd;
                    t++;
                    if(tsum > s) break;
                }
                if(tsum == s) count++;
            }

            low++;
        }
        return count;
    }
};