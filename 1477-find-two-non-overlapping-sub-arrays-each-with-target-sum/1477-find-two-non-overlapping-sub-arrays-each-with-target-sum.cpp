class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        int l = 0;
        int best = INT_MAX;
        vector<int> dp(n,INT_MAX);
        int ans = INT_MAX;
        int sum =0;

        for (int r = 0; r < n; r++) {
            sum = sum + arr[r];

            while (sum > target) {
                sum = sum - arr[l];
                l++;
            }

            if (sum == target) {
                int len = r - l + 1;

                if (l != 0 && dp[l - 1] != INT_MAX) {
                    ans = min(ans, len + dp[l - 1]);
                }

                best = min(best, len);
            }
            dp[r] = best;
        }
        return ans == INT_MAX ? -1 : ans;
    }
};