class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>prefix(nums.size());
        vector<int>product(nums.size());
        prefix[0] = 1;
        for(int i = 1;i<nums.size();i++){
            prefix[i] = prefix[i-1] * nums[i-1];
        }
        int suffixprod = 1;
        for(int i = nums.size()-1;i>=0;i--){
            product[i] = suffixprod * prefix[i];
            suffixprod = suffixprod * nums[i];
        }
    return product;
    }
};