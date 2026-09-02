class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> mp;
        int sum = 0;
        int f = 0;

        for(int i = 0 ; i < nums.size() ; i++){
            mp[nums[i]]++;
            if(mp[nums[i]] > f) f = mp[nums[i]];
        }

        for(auto it : mp){
            if(it.second == f) sum = sum + it.second;
        }
        return sum;
    }
};