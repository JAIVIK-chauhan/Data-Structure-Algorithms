class Solution {
public:
    long long shadowPairs(vector<int>& nums) {
        long long ans = 0;
        stack<pair<int,int>> st;
        int total = 0;

        for(int i = 0 ; i < nums.size() ; i++){

            while(!st.empty() && st.top().first > nums[i]){
                total = total - st.top().second;
                st.pop();
            } 
            if(st.empty()){
                st.push({nums[i],1});
                total++;
            }
            else if(st.top().first == nums[i]){
                int f = st.top().second;
                ans = ans + total - f;
                
                st.top().second++;
                total++;
            }
            else{
                st.push({nums[i],1});
                ans = ans + total;
                total++;
            }
        } 
        return ans;
    }
};