class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1);
        
        for (int i = 2; i <= n; i++) {
            dp[i] = min(dp[i - 1] + cost[i - 1],
                        dp[i - 2] + cost[i - 2]);
        }
        // dp[0] = cost[0];
        // dp[1] = min(cost[1], cost[0]);
        // for (int i = 2; i < n; i++) {
        //     dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
        // }
        
        // return min(dp[n-1], dp[n-2]);
        return dp[n];
    }
};