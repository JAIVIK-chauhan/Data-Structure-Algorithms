class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin(),nums.end());

        while(!nums.empty()){
            int prev = -1;
            int size = nums.size();
            int i = 0;

            while(i < size){
                if (nums[i] != prev) {
                    prev = nums[i];
                    ans.push_back(nums[i]);
                    nums.erase(nums.begin() + i);
                } 
                else i++;    
            }
        }
        return ans;
    }
};