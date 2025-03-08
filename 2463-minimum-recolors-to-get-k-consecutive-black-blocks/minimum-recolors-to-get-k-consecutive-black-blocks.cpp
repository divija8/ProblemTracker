class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int ans = INT_MAX, count = 0;
        for(int i = 0;i < k ;i++){
            if(blocks[i] == 'W'){
                count++;
            }
        }
        ans = min(ans, count);
        for(int i = k; i<blocks.size();i++){
            if(blocks[i] == 'W'){
                count++;
            }
            if(blocks[i-k] == 'W'){
                count--;
            }
            ans = min(ans, count);
        }
        return ans;
    }
};