class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n = nums.size()/2;
        sort(nums.begin(),nums.end());

        int i = 0;
        while(i < nums.size()-1){
            if(nums[i] == nums[i+1]) i = i + 2;
            else return false;
        }
        return true;
    }
};