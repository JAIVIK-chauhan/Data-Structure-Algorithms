class Solution {
public:
    bool isUgly(int n) {
        while(n){
            int dig = n%2;
            if(dig == 0){
                n = n / 2;
            }
            else break;
        }

        while(n){
            int dig = n%3;
            if(dig == 0) n = n / 3;
            else break;
        }

        while(n){
            int dig = n%5;
            if(dig == 0) n = n / 5;
            else break;
        }

        if(n == 1) return true;
        else return false;
    }
};