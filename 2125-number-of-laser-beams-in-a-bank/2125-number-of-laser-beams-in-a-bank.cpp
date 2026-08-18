class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int> beams;
        int ans = 0;

        for(int i = 0 ; i < bank.size() ; i++){
            int c = 0;
            for(int j = 0 ; j < bank[i].length() ; j++){
                if(bank[i][j] == '1') c++;
            }
            if(c != 0) beams.push_back(c);
        }

        for(int i = 0 ; i+1 < beams.size() ; i++){
            ans = ans + (beams[i] * beams[i+1]);
        }
        return ans;
    }
};