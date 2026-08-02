class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int cmp = a / b;
        int global = 0;

        for (int i = 0; i < nums.size(); i++) {
            int even = 0;
            int odd = 0;

            for (int j = i; j < nums.size(); j++) {

                if (nums[j] % 2)
                    odd++;
                else
                    even++;

                if (odd != 0) {
                    if (even * b <= odd * a)
                        global++;
                }
            }
        }
        return global;
    }
};