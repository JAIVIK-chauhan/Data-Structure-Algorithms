class Solution {
public:
    int reverse(int x) {
        int num = 0;
        int n = x;
        if (x == INT_MIN)
            return 0;

        if(x<0)
            x = -1*x;

        while(x>0){
            int temp = x % 10;
            if(num > INT_MAX/10)
                return 0;
            num = 10*num + temp;
            x = x / 10;
        }

        if(n<0)
            return -1*num;

        else
            return num;
    }
};