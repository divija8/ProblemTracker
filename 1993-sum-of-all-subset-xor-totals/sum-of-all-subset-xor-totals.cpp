class Solution {
public:
    int dfs(vector<int>&nums, int index, int cXOR){
        if(index == nums.size()){
            return cXOR;
        }
        int take = dfs(nums, index + 1, cXOR ^ nums[index]);
        int notTake = dfs(nums, index + 1, cXOR);
        return take + notTake;

    }
    int subsetXORSum(vector<int>& nums) {
        return dfs(nums, 0, 0);
    }
};