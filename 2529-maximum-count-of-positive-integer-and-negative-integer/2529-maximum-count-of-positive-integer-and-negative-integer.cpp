class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int c = 0;
        int ans = 0;
        int n = nums.size();
        int i = 0;
        while(i < nums.size() && nums[i] <= 0){
            if(nums[i] < 0) c++;
            i++;
        }
        ans = max(c,n-i);
        return ans;
    }
};