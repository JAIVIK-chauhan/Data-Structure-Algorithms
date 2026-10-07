class Solution {
public:
    void solve(int i, int n , int k , vector<vector<int>>& ans, vector<int>& ds){
        if(ds.size() == k){
            ans.push_back(ds);
            return;
        }
        if(i > n) return;
        ds.push_back(i);
        solve(i+1,n,k,ans,ds);
        ds.pop_back();
        solve(i+1,n,k,ans,ds);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> ds;

        solve(1,n,k,ans,ds);
        return ans;
    }
};