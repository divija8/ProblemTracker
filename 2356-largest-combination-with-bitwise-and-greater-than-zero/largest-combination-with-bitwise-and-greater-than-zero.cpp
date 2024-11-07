class Solution {
public:
    int largestCombination(vector<int>& cd) {
        int ans = 1;
        // unordered_map<int, int>u;
        for(int i=0;i<=31;i++) {
            int cnt = 0;
            // cout<<i<<": ";
            for(int j=0;j<cd.size();j++) {
                if(cd[j]>>i&1) {
                    cnt++;
                }
            }
            // cout<<endl;
            ans = max(ans, cnt);
        }
        return ans;
    }
};