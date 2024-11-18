class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int ans = 0, count = 0;
       for(int i =1; i< nums.size(); i++)
       {
        if(nums[i-1] < nums[i])
        count++;
        else
        count = 0;
        ans = max(ans,count);
    }
      return ans+1;  
    }
};