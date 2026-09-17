class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        int c = 0;
        if(k == 0) return nums.size();
        sort(nums.begin(),nums.end());
       for(int i = 0 ; i < nums.size() ; i++){
        if(nums[i] < nums[nums.size()-k]) c++;
       }
       return c;
    }
};