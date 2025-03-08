class Solution {
public:

    // int rob2(vector<int>& nums, int st, int end) {
    //     int t1 = 0, t2 = 0;
    //     for (int i = st; i <= end; ++i) {
    //         int temp = t1;
    //         t1 = max(nums[i] + t2, t1);
    //         t2 = temp;
    //     }

    //     return t1;
    // }
    int rob2(vector<int>&nums,int start, int end)
    {
        int n=end-start+1;
        if(n==0)
        return nums[0];
        if(n==1)
        return nums[start];
        int dp[n];
        dp[0]=nums[start];
        dp[1]=max(nums[start],nums[start+1]);
        for(int i=2;i<n;i++)
        {
            dp[i]=max(dp[i-1],nums[start+i]+dp[i-2]);
        }
        return dp[n-1];
    }
    int rob(vector<int>& nums) {
      int n = nums.size();
      int max1 = rob2(nums, 0, n-2);
      int max2 = rob2(nums, 1, n-1);
      return max(max1, max2);

    }
};