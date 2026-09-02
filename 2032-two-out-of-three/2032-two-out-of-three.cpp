class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        vector<int> ans;
        unordered_set<int> s;
        unordered_map<int,int> mp;

        int i = 0;
        while(i < nums1.size()) s.insert(nums1[i++]);
        for(auto it : s) mp[it]++;

        s.clear();
        i = 0;

        while(i < nums2.size()) s.insert(nums2[i++]);
        for(auto it : s) mp[it]++;

        s.clear();
        i = 0;

        while(i < nums3.size()) s.insert(nums3[i++]);
        for(auto it : s) mp[it]++;

        for(auto it : mp){
            int f = it.second;
            if(f >= 2) ans.push_back(it.first);
        }
        return ans;
    }
};