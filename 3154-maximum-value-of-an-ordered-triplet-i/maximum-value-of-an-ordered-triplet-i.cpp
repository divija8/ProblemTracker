class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();

        vector<int> left(n, 0);
        vector<int> right(n, 0);

        left[0] = nums[0];

        for(int i=1;i<n;i++)
        {
            left[i] = max(left[i-1], nums[i]);
        }

        right[n-1] = nums[n-1];

        for(int i=(n-2);i>=0;i--)
        {
            right[i] = max(right[i+1], nums[i]);
        }
        long long int ans = 0;

        for(int j=1;j<(n-1);j++)
        {
           
            ans = max(ans, (max(left[j-1] - nums[j],0))*(long long int)right[j+1]);
        }

        return ans;
    }
};