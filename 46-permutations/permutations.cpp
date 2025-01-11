class Solution {
public:
    void generatePerm(vector<int>&nums, vector<int>&ds, vector<vector<int>>&ans, int freq[]){
        if(ds.size() == nums.size()){
            ans.push_back(ds);
            return;
        }
        for(int i = 0;i<nums.size();i++){
            if(!freq[i]){
                freq[i] = true;
                ds.push_back(nums[i]);
                generatePerm(nums, ds, ans, freq);
                ds.pop_back();
                freq[i] = false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>ds;
        int freq[nums.size()];
        for(int i =0;i<nums.size();i++){
            freq[i] = 0;
        }
        generatePerm(nums, ds, ans, freq);
        return ans;
    }
};