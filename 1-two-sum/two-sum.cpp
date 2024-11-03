class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int>cmap;
        for(int i= 0;i<nums.size();i++){
            int value = target - nums[i];
            if(cmap.find(value) != cmap.end()){
                return {cmap[value], i};
            } else {
                cmap[nums[i]] = i;
            }
        }
        return {};
    }
};