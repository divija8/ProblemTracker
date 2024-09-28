class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int>ans;
        unordered_map<int, int>cmap;
        for(auto i : nums){
            cmap[i]++;
        }
        for(auto i : cmap){
            if(i.second == 2){
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};