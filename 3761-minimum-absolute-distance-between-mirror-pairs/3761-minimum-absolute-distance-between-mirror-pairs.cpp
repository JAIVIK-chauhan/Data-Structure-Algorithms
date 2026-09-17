class Solution {
public:

    int reves(int num){
         int rev = 0;
         while(num > 0){
                int dig = num % 10;
                num = num / 10;
                rev = (rev * 10) + dig;
            }
        return rev;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        int dist = INT_MAX;
        unordered_map<int,int> mp;

        for(int i = 0 ; i < nums.size() ; i++){

            if(mp.find(nums[i]) != mp.end()){
                dist = min(dist,abs(i-mp[nums[i]]));
            }
            int rev = reves(nums[i]);
            mp[rev] = i;
        }
        if(dist == INT_MAX) return -1;
        return dist;
    }
};