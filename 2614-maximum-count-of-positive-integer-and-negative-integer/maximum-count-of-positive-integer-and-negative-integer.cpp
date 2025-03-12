class Solution {
public:
    int lastIndexofNegative(vector<int>&nums,int left,int right){
        while(left<=right){
            int mid=(left+right)/2;
            if(nums[mid]>=0){
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return right+1;
    }
    int startIndexofPositive(vector<int>&nums,int left,int right){
        while(left<=right){
            int mid=(left+right)/2;
            if(nums[mid]<=0){
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        return nums.size()-left;
    }
    int maximumCount(vector<int>& nums) {
        int n=nums.size();
        return max(lastIndexofNegative(nums,0,n-1),startIndexofPositive(nums,0,n-1));
    }
};