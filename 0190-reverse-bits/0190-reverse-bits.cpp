class Solution {
public:
    int reverseBits(int n) {
        vector<int> bits;
        int k = 0;
        while(k < 32){
            int dig = n%2;
            n = n / 2;
            bits.push_back(dig);
            k++;
        }

        //reverse(bits.begin(),bits.end());
        int num = 0;

        for(int i = 0 ; i < 32; i++){
            num = num * 2 + bits[i];
        }
        return num;
    }
};