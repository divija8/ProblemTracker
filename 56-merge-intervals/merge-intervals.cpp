class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>>res;
        int s = intervals[0][0], e = intervals[0][1];
        for(int i = 1 ; i<intervals.size();i++){
            if(intervals[i][0] <= e) {
                s = min(intervals[i][0], s);
                e = max(e, intervals[i][1]);
            } else {
                res.push_back({s, e});
                s = intervals[i][0];
                e = intervals[i][1];
            }

        }
        res.push_back({s, e});
        return res;
    }
};