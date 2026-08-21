class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int,int> mp;
        int sum = 0;

        for(int i = 0 ; i < nums.size() ; i++){
            mp[nums[i]]++;
        }

        for(auto it : mp){
            int num = it.first;
            int freq = it.second;

            if(freq == 1) sum = sum + num;
        }
        return sum;
    }
};