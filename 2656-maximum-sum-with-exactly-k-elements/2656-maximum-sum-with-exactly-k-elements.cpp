class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int mx = 0;
        int ans = 0;

        for(int i = 0 ; i < nums.size() ; i++){
            mx = max(nums[i],mx);
        }

        while(k){
            ans = ans + mx;
            mx++;
            k--;
        }
        return ans;
    }
};