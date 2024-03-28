class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int>cmap;
        int left = 0, right = 0, ans = 0;
        while(left<nums.size() && right<nums.size()){
            cmap[nums[right]]++;
            while(cmap[nums[right]]>k){
                cmap[nums[left]]--;
                left++;
            }
            ans = max(ans, right-left+1);
            right++;
        }
        return ans;
    }
};