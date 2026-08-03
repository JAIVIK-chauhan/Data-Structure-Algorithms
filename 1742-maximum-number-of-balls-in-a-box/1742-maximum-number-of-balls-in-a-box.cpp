class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        unordered_map<int,int> mp;
        int ans = 0;

        for(int i = lowLimit ; i <= highLimit ; i++){
            int num = i;
            int sum = 0;
            while(num){
                int dig = num%10;
                num = num/10;
                sum = sum + dig;
            }
            mp[sum]++;
        }

        for(auto it : mp){
            int freq = it.second;
            ans = max(ans,freq);
        }
        return ans;
    }
};