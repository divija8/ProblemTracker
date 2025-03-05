class Solution {
public:
    long long coloredCells(int n) {
        long long ans = 1;
        long long c = 0;
        for(int i = 1;i <= n; i++){
           c += ans;
           ans = 4 * i;
        }
        return c;
    }
};