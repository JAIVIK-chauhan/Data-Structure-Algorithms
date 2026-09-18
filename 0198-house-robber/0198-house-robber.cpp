class Solution {
public:
    int rob(vector<int>& nums) {
      if(nums.size() <= 1)
        return nums[0];
      int max1 = nums[0];
      int max2 = max(nums[0],nums[1]);
      
      for(int i = 2 ; i < nums.size() ; i++){
        int temp = max1 + nums[i];
        max1 = max2;
        max2 = max(temp,max2);
      }
      return max2;
    }
};