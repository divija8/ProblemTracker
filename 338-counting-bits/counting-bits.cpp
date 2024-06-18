class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1); 
        for (int j = 0; j <= n; j++) {
            int count = 0;
            int num = j;
            while (num > 0) {
                count += num & 1; 
                num >>= 1;        
            }
            ans[j] = count;
        }
        return ans;
    }
};
