class Solution {
public:
    void subsetgen(int i, vector<int>&ds, vector<vector<int>>&ans, vector<int>&nums){
        if(i >= nums.size()){
            ans.push_back(ds);
            return;
        }
        ds.push_back(nums[i]);
        subsetgen(i+1, ds, ans, nums);
        ds.pop_back();
        subsetgen(i+1, ds, ans, nums); 
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>ds;
        subsetgen(0, ds, ans, nums);
        return ans;
    }
};