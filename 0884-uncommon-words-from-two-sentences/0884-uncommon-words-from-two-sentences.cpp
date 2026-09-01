class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> ans;
        unordered_map<string,int> mp;
        string str = "";

        int i = 0;
        while(i < s1.length()){
            if(s1[i] != ' ' && i != s1.length()-1){
                str = str + s1[i];
            }
            else{
                if(i == s1.length() -1) str = str + s1[i];
                mp[str]++;
                str = "";
            }
            i++;
        }
        int j = 0;
        str = "";
        while(j < s2.length()){
            if(s2[j] != ' ' && j != s2.length()-1){
                str = str + s2[j];
            }
            else{
                if(j == s2.length() -1) str = str + s2[j];
                mp[str]++;
                str = "";
            }
            j++;
        }
        for(auto it : mp){
            string s = it.first;
            int f = it.second;

            if(f == 1) ans.push_back(s);
        }
        return ans;
    }
};