class Solution {
public:
    int thirdMax(vector<int>& nums) {

        unordered_set<int> st;

        for(int i =0 ; i < nums.size() ; i++)
            st.insert(nums[i]);

        vector<int> num(st.begin(),st.end());
        sort(num.begin(), num.end());

        if(num.size() < 3) return num[num.size()-1];
        else return num[num.size()-3];
    }
};