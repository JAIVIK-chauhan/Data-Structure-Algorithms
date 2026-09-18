class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        int c = 0;
        unordered_set<int> s;
        for(int i = 0 ; i < nums.size()-1 ; i++){
          int sum = nums[i] + nums[i+1];
          if(s.contains(sum)) return true;
          else s.insert(sum);
        }
        return false;
    }
};