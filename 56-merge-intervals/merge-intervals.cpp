class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1)
            return intervals;
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;
        int s = intervals[0][0], e = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= e) {
                s = min(s, intervals[i][0]);
                e = max(e, intervals[i][1]);
            } else {
                result.push_back({s, e});
                s = intervals[i][0];
                e = intervals[i][1];
            }
        }
        result.push_back({s, e});
        return result;
    }
};