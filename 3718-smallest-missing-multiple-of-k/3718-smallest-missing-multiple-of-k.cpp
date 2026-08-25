class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> s(nums.begin(), nums.end());

        int fg = 0;
        int n = k;

        while(s.contains(n)) n = n + k;
        return n;
    }
};