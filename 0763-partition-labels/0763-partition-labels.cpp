class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> mp;
        vector<int> ans;

        for(int i = 0 ; i < s.length() ; i++){
            mp[s[i]] = i;
        }
        int end = 0;
        int start = 0;
        for(int i = 0  ; i < s.length() ; i++){
            end = max(end,mp[s[i]]);

            if(i == end){
                ans.push_back(end - start + 1);
                start = end+1;
            }
        }
        return ans;
    }
};