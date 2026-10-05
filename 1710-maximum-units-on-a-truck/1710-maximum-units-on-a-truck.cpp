class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(),
             [](vector<int>& a, vector<int>& b) { return a[1] > b[1]; });
        int s = 0;
        int i = 0;
        int ans = 0;

        while(s <= truckSize && i < boxTypes.size()){
            int box = boxTypes[i][0];
            int unit = boxTypes[i][1];

            if(s + box > truckSize){
                int temp = truckSize - s;
                s = s + temp;
                ans = ans + (temp * unit);
            }
            else{
                s = s + box;
                ans = ans + (box * unit);
            }
            i++;
        }
        return ans;
    }
};