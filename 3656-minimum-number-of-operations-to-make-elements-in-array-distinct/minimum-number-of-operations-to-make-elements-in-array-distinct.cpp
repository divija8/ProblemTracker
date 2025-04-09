class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ct=0;
        int start = 0;
        while(start < nums.size()){
            unordered_set<int>seen;
            bool dup = false;
            for(int i = start;i< nums.size();i++){
                if(seen.count(nums[i])){
                    dup = true;
                    break;
                }
                seen.insert(nums[i]);
            }
            if(!dup){
                break;
            }
            start += 3;
            ct++;
        }
    return ct;
    }
};