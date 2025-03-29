class Solution {
public:
    bool divideArray(vector<int>& nums) {
        if(nums.size() % 2 != 0) return false;
        unordered_map<int, int>umap;
        for(auto i : nums){
            umap[i]++;
        }
        for(auto i : umap){
            if(i.second % 2 != 0){
                return false;
            }
        }
        return true;
    }
};