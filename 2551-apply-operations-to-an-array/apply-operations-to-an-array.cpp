class Solution {
public:
    void moveZero(vector<int>& nums){
        int p = 0, c = 0;
        while(c < nums.size()){
            if(nums[c] != 0) {
                swap(nums[c], nums[p++]);
            }
            c++;
        }

    }
    vector<int> applyOperations(vector<int>& nums) {
        for(int i = 0;i<nums.size()-1;i++){
            if(nums[i] == nums[i+1]){
                nums[i] *= 2;
                nums[i+1] = 0;
            } 
            else {
                continue;
            }
        }
        moveZero(nums);
        return nums;
    }
};