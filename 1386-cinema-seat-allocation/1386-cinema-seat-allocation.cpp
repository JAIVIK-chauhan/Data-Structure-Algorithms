class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        sort(reservedSeats.begin(), reservedSeats.end());
        int c = 0;
        int i = 0;
        int row = 0;

        while(i < reservedSeats.size()){
            int x = reservedSeats[i][0];
            int fg = 0;
            vector<int> seat(11,0);
           

            while(i < reservedSeats.size() &&  x == reservedSeats[i][0]){
                fg = 1;
                int ele = reservedSeats[i][1];
                seat[ele] = 1;
                i++;
            }
            row++;
            bool left = (seat[2] == 0 &&
                         seat[3] == 0 &&
                         seat[4] == 0 &&
                         seat[5] == 0);

            // Block 4,5,6,7
            bool middle = (seat[4] == 0 &&
                           seat[5] == 0 &&
                           seat[6] == 0 &&
                           seat[7] == 0);

            // Block 6,7,8,9
            bool right = (seat[6] == 0 &&
                          seat[7] == 0 &&
                          seat[8] == 0 &&
                          seat[9] == 0);
            
            if (left && right)
                c += 2;
            else if (left || middle || right)
                c += 1;
        }
        return c + (n-row)*2;
    }
};