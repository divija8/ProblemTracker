class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int res = 0;
        int prevEnd = intervals[0][1];
        for(int i = 1; i < intervals.size();i++){
           int s = intervals[i][0];
           int e = intervals[i][1];
           if(s >= prevEnd) {
                prevEnd = e;
           } else {
                res++;
                prevEnd = min(prevEnd, e);
           }
        }
        return res;
    }
};