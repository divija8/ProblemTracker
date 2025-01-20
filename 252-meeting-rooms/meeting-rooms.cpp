class Solution {
public:

    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if(!intervals.size()) return true;
        sort(intervals.begin(), intervals.end(), [&](vector<int>& a, vector<int>&b) {
            if(a[1]==b[1]) return a[0]<b[0];
            return a[1]<b[1];
        });
        for(int i=0;i<intervals.size()-1;i++) {
            if(intervals[i][1]>intervals[i+1][0]) return false; 
        }
        return true;
    }
};