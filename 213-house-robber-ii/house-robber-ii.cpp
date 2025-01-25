class Solution {
public:

    int rob2(vector<int>& nums, int st, int end) {
        int t1 = 0, t2 = 0;
        for (int i = st; i <= end; ++i) {
            int temp = t1;
            t1 = max(nums[i] + t2, t1);
            t2 = temp;
        }

        return t1;
    }

    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;

        if (nums.size() == 1) return nums[0];
        int n = nums.size();

        return max(rob2(nums, 0, n-2), rob2(nums, 1, n-1));
    }
};