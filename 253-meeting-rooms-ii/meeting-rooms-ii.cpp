class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int ans = 1, n= intervals.size(), cnt = 1;
        if(n==1) return 1;
        vector<int>st, en;
        for(int i=0;i<n;i++) {
            st.push_back(intervals[i][0]);
            en.push_back(intervals[i][1]);
        }
        sort(st.begin(), st.end());
        sort(en.begin(), en.end());

        int i = 0, j = 1;
        while(i<n && j<n) {
            if(st[j]>=en[i]) {
                cnt--;
                i++;
            } else {
                cnt++;
                j++;
            }
            ans = max(cnt, ans);
        }
        return ans;
    }
};