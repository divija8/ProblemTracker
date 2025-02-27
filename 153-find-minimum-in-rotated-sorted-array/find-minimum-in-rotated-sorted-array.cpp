class Solution {
public:
    int findMin(vector<int>& nums) {
        int ans = INT_MAX;
        int low = 0, high = nums.size() - 1;
        while(low <= high){
            int mid = (low + high)/2;
            if(nums[low] <= nums[mid]){
                ans = min(nums[low], ans);
                low = mid + 1 ;
            } else {
                ans = min(nums[mid], ans);
                high = mid - 1;
            }
        }
        return ans;
    }
};