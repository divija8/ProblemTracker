class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        int cnt=nums[0];
        int maxi=0;
        for(int i=0; i<n-1; i++){
            if(nums[i+1]>nums[i]){
                cnt+=nums[i+1];
                maxi = max(maxi, cnt);
            }else{
                maxi = max(maxi, cnt);
                cnt=nums[i+1];
            }
        }
        return maxi;
    }
};