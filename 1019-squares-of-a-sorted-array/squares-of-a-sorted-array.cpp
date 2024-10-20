class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int i = 0, j = nums.size()-1, k = nums.size()-1;
        vector<int>ans(nums.size(), 0);
        while(k >= 0){
            if(nums[i] * nums[i] > nums[j] * nums[j]){
                ans[k] = nums[i]*nums[i];
                k--;
                i++;
            }else {
                ans[k] = nums[j] * nums[j];
                j--;
                k--;
            }
        }
        return ans;
    }
};