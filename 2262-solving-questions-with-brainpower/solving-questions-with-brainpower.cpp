class Solution {
public:
    typedef long long ll;
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<ll>dp(n,0);
        for(int ind=n-1;ind>=0;ind--){
            ll solve = questions[ind][0] + (ind + questions[ind][1] + 1 < n ? dp[ind + questions[ind][1] + 1] : 0);
            ll skip = (ind+1<n ? dp[ind+1] : 0);

            dp[ind] = max(solve,skip);
        }
        return dp[0];
    }
};