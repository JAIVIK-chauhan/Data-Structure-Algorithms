class Solution {
public:
    bool checkPowersOfThree(int n) {
        while(n){
            int dig = n % 3;
            n = n/3;
            if(dig == 2) return false;
        }   
        return true;
    }
};