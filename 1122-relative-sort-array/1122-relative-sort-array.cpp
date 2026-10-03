class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> ans;
        unordered_map<int,int> mp;
        vector<int> ds;

        for(int i = 0 ; i < arr1.size() ; i++){
            mp[arr1[i]]++;
        }

        for(int i = 0 ; i < arr2.size() ; i++){
            int c = mp[arr2[i]];
            for(int j = 0 ; j < c ; j++){
                ans.push_back(arr2[i]);
                mp[arr2[i]]--;
            }
        }
        for(auto it : mp){
            if(it.second > 0){
                int f = it.second;
                for(int i = 0 ; i < f ; i++)
                    ds.push_back(it.first);
            }
        }
        sort(ds.begin(),ds.end());
        for(int i = 0 ; i < ds.size() ; i++) ans.push_back(ds[i]);

        return ans;
    }
};