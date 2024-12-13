class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        unordered_set<int>cset;
        for(auto i : nums){
            cset.insert(i);
        }
        for(auto i : cset){
            if(cset.count(i-1)){
                continue;
            }
            int t = i;
            int len = 1;
            while(cset.count(++t)){
                len++;
            }
        ans = max(ans, len);
        }
       return ans; 
    }
};