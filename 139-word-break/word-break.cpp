class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size() + 1, false);
        dp[s.size()] = true;

        for (int i = s.size() - 1; i >= 0; i--) {
            for (const auto& w : wordDict) {
                if ((i + w.size()) <= s.size() && dp[i + w.size()]&&
                     s.substr(i, w.size()) == w) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[0];
    }
};