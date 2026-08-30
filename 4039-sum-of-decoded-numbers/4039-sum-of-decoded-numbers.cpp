class Solution {
public:
    int sumDecoded(vector<long long>& nums) {
        long long mod = 1e9 + 7;
        int sum = 0;

        for(int i = 0 ; i < nums.size() ; i++){
            int width = nums[i] % 10;
            long long d = nums[i] / 10;

            long long n = d;
            vector<int> v;
            while(n){
                int dig = n % 10;
                n = n / 10;
                v.push_back(dig);
            }
            long long x = 0;
            //reverse(v.begin(),v.end());
            int idx = v.size()-1;
            int w = width;
            while(w){
                x = (x*10) + v[idx];
                idx--;
                w--;
            }
            int y = 0;
            while(idx >= 0){
                y = (y*10) + v[idx];
                idx--;
            }
            long long form = 1;
            x = x % mod;
            long long j = y;
            
            while(j > 0) {
                if(j % 2 == 1)
                    form = (form * x) % mod;
                x = (x * x) % mod;
                j = j / 2;
            }
            sum = (sum + form) % mod;
        }
        return sum;
    }
};