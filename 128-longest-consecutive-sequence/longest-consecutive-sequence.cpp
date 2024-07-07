class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>cset;
        int max_len = 0;
        for(auto i : nums){
            cset.insert(i);
        }
        for(auto i : nums){
            if(!cset.count(i-1)){
                int current_num = i;
                int current_streak = 1;
            while(cset.count(current_num+1)){
                current_num +=1;
                current_streak +=1;
            }
            max_len = max(max_len, current_streak);
        }
        }
        return max_len;
    }
};

