class Solution {
public:
      void cSum(int index, int target, vector<int>&candidates, vector<int>&ds, vector<vector<int>>&ans){
        if(index == candidates.size()){
            if(target == 0){
                ans.push_back(ds);
            }
            return;
        }
        if(candidates[index] <= target){
            ds.push_back(candidates[index]);
            cSum(index, target-candidates[index], candidates, ds, ans);
            ds.pop_back();
        }
        cSum(index+1, target, candidates, ds, ans);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        cSum(0, target, candidates, ds, ans);
        return ans;
    }
};