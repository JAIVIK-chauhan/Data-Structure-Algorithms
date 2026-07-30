class Solution {
public:
    int minimumPushes(string word) {
         unordered_map<char, int> mp;
    int ans = 0;
    int sum = 0;

    for (int i = 0; i < word.size(); i++) {
        mp[word[i]]++;
    }

    if (mp.size() <= 8) {
        for (auto it : mp) {
            int freq = it.second;
            sum = sum + freq;
        }
        return sum;
    } else {
        int c = 0;
        for (auto it : mp) {
            int freq = it.second;
            if (c < 8) {
                sum = sum + freq;
                c++;
            } else if (c < 16) {
                sum = sum + (freq * 2);
                c++;
            } else if (c < 24) {
                sum = sum + (freq * 3);
                c++;
            } else {
                sum = sum + (freq * 4);
                c++;
            }
        }
    }
    return sum;
    }
};