class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int ans=nums.size();
        for(int i=0; i<nums.size(); i++){
            if(nums[i]<1 || nums[i]>ans) nums[i]=ans+1;
        }

        for(int i=0; i<nums.size(); i++){
            int temp=abs(nums[i]);
            if(temp >= 1 && temp <= ans){
                if(nums[temp-1] > 0) nums[temp-1]*=-1;
            }
        }

        for(int i=0; i<nums.size(); i++){
            if(nums[i]>0) return i+1;
        }
        return ans+1;
    }
};