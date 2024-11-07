class Solution {
public:
    int largestCombination(vector<int>& cd) {
        int ans = 1;
        for(int i=0;i<=31;i++) {
            int cnt = 0;
            for(int j=0;j<cd.size();j++) {
                if(cd[j]>>i&1) {
                    cnt++;
                }
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};
