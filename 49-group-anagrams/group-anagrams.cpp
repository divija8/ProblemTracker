class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        unordered_map<string, vector<string>>cmap;
        for(int i = 0;i<strs.size();i++){
            string strsval = strs[i];
            sort(strsval.begin(), strsval.end());
            cmap[strsval].push_back(strs[i]);
        }
        for(auto i : cmap){
            ans.push_back(i.second);
        }
        return ans;
    }
};