class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans;
        string c1 = "FizzBuzz";
        string c2 = "Fizz";
        string c3 = "Buzz";

        for(int i = 1 ; i <= n ; i++){
            if(i % 3 == 0 && i % 5 == 0) ans.push_back(c1);
            else if(i % 3 == 0) ans.push_back(c2);
            else if(i % 5 == 0) ans.push_back(c3);
            else ans.push_back(to_string(i));
            
        }
        return ans;
    }
};