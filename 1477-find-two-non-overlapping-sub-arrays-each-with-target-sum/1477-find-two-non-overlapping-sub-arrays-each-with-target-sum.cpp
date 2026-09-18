class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        int l = 0 , sum = 0;
        int best = INT_MAX;
        vector<int> v(n,INT_MAX);
        int ans = INT_MAX;

        for(int r = 0 ; r < n ; r++){
            sum = sum + arr[r];

            while(sum > target){
                sum = sum - arr[l];
                l++;
            }

            if(sum == target){
                int len = r-l+1;

                if(l != 0 && v[l-1] != INT_MAX){
                    ans = min(ans, len + v[l-1]);
                }
                best = min(best,len);
            }
            v[r] = best;
        }
        return ans == INT_MAX ? -1:ans;
    }
};