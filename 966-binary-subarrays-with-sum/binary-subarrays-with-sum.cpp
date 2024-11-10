class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int sum = 0;
        int cnt = 0;
        unordered_map<int,int> mpp;
        mpp[0]=1;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int pre = sum-goal;
            if(mpp[pre]!=0) cnt+=mpp[pre];
            mpp[sum] = mpp[sum]+1;
        }
        return cnt;
    }
};