class Solution {
public:
    int largestInteger(int n, int s) {

        string str = "";

        if(s > 9*n) return -1;

        for(int i = 0 ; i < n ; i++){
            int dig = min(9,s);

            str = str + char(dig + '0');
            s = s - dig;
        }
        int num = stoi(str);
        return num;
    }
};