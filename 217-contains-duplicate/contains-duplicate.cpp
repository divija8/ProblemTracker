class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int>sval;
        for(auto i : nums){
            sval.insert(i);
        }
    return nums.size() != sval.size();
    }
};