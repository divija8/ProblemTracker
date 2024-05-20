class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int res = 0;
        for(int i = 0;i<nums.size();i++){
            res |= nums[i];
        }
        return res <<(nums.size()-1);
    }
};