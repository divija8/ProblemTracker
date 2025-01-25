// class Solution {
// public:
//     int minCostClimbingStairs(vector<int>& cost) {
//         int n = cost.size();
//         vector<int> dp(n + 1);
        
//         for (int i = 2; i <= n; i++) {
//             dp[i] = min(dp[i - 1] + cost[i - 1],
//                         dp[i - 2] + cost[i - 2]);
//         }
//         dp[0] = cost[0];
//         // dp[1] = min(cost[1], cost[0]);
//         dp[1] = cost[1];
//         for (int i = 2; i < n; i++) {
//             dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
//         }
        
//         return min(dp[n-1], min(dp[n-2], dp[n-3]));
//         // return dp[n];
//     }
// };

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // recursive function: f(n) = min(f(n-1), f(n-2)) + c(n) where f(n) is min cost for 1...n, c(n) is cost for current n

        if (cost.size() == 0) {
            return 0;
        }
        if (cost.size() == 1) {
            return cost[0];
        }
        int f_n_2 = cost[0];
        int f_n_1 = cost[1];
        int f_n = cost[1];
        for (int i = 2; i < cost.size(); i++) {
            f_n = min(f_n_1, f_n_2) + cost[i];
            f_n_2 = f_n_1;
            f_n_1 = f_n;
        }
        return min(f_n, f_n_2);
    }
};