class Solution {
public:
    int getSetBits(int num){
        int count = 0;
        while (num!=0){
            if (num & 1) count++;
            num = num >> 1;
        }
        return count;
    }

    bool canSortArray(vector<int>& nums) {
        vector<int> copy = nums;
        sort(copy.begin(), copy.end());
        int n = nums.size();
        for (int j=0; j<n-1; j++){
            bool canSwap = false;
            for (int i=0; i<nums.size()-1; i++){  
                if (nums[i]>nums[i+1] && (getSetBits(nums[i])==getSetBits(nums[i+1]))){
                    swap(nums[i], nums[i+1]);
                    canSwap = true;
                }
            }
            if (canSwap == false) break;
        }
        return (copy==nums);
    }
};