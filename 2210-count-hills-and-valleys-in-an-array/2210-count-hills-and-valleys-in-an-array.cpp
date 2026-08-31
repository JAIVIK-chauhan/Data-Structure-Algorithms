class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int c = 0;

        int i = 1;

        while(i < nums.size()-1){

            if(nums[i] < nums[i-1] && nums[i] < nums[i+1]) c++;

            else if(nums[i] > nums[i-1] && nums[i] > nums[i+1]) c++;
            
            else if(nums[i] > nums[i-1] && nums[i] == nums[i+1]){
                int pr = nums[i-1];
                while(i < nums.size()-2 && nums[i] == nums[i+1]) i++;
                if(nums[i] > nums[i+1]) c++;
            }
            else if(nums[i] < nums[i-1] && nums[i] == nums[i+1]){
                int pr = nums[i-1];
                while(i < nums.size()-2 && nums[i] == nums[i+1]) i++;
                if(nums[i] < nums[i+1]) c++;
            }
            i++;
        }
        return c;
    }
};