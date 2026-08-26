class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> ans;
        int idx = 0;
        int f = 0;

        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] < target) idx++;
            else if(nums[i] == target) f++;
        }

        while(f){
            ans.push_back(idx++);
            f--;
        }
        return ans;
    }
};