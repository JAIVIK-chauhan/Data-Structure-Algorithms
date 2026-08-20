class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int xorr = 0;
        int fg = 1;

        for(int i  = 0 ; i < nums.size() ; i++){
            xorr = xorr ^ nums[i];

            if(nums[i] != 0) fg = 0;
        }
        if(fg == 1) return 0;
        if(xorr == 0) return n-1;
        else return n;
        
    }
};