class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int,vector<int>> mp;
        int c = 0;

        for(int i = 0 ; i < nums.size() ; i++){
            mp[nums[i]].push_back(i);
        }

        for(auto it : mp){
            vector<int> v = it.second;
            if(v.size() != 3 ) continue;
            if(v[1] - v[0] == v[2] - v[1]) c++;
        }
        return c;
    }
};