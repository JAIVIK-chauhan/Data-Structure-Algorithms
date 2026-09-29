class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = 0;
        int target = 0;

       for(int i =0 ; i < nums.size() ; i++){
        sum += nums[i];
       } 
       target = sum - x;
       if(target < 0)
            return -1;
        if(target == 0)
            return nums.size();

        int s = 0;
        int ans = -1;
        int j = 0;
        int i = 0;

      while(i < nums.size()){
        s = s + nums[i];
       
        while(s > target ){
                s = s - nums[j];
                j++;
        }
        
        if(s == target){
            int len = i - j + 1;
            ans = max(ans,len);
        }
        i++;
        
       }
       if(ans == -1) return -1;
        return nums.size()-ans;
    }
};