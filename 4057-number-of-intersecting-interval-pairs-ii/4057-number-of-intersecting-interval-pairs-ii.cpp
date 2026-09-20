class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
        long long p = 0;

        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> pq;

        pq.push(intervals[0][1]);
        int i = 1;

        while(i < intervals.size()){
            int start = intervals[i][0];
            int end = intervals[i][1];

            while(!pq.empty() && pq.top() < start) pq.pop();
            p = p + pq.size();

            pq.push(end);
            i++;
        }
        return p;
    }
};