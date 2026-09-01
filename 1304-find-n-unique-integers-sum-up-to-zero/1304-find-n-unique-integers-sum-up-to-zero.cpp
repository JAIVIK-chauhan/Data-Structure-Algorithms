class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;
        int s = n / 2;

        for (int i = 0; i <= s; i++) {
            if (i == 0) {
                if(n % 2 == 1){
                    ans.push_back(i);
                    continue;
                } else continue;
                
            }

            ans.push_back(i);
            ans.push_back(-i);
        }
        return ans;
    }
};