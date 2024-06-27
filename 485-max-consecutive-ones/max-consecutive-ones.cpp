class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
       int max_count = 0;
        int maxi = INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1) max_count++;
            else {
                max_count = 0;
            }
            maxi = max(maxi, max_count);
        }
        return maxi;
    }
};