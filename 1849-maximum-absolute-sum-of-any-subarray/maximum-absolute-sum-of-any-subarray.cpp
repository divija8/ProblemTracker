class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int psum = 0, minsum = 0, maxsum= 0;
        for(int i = 0;i<nums.size();i++){
            psum += nums[i];
            minsum = min(minsum, psum);
            maxsum = max(maxsum, psum);
        }
        return maxsum- minsum;
    }
};