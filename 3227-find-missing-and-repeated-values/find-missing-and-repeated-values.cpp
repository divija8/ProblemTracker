class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        // vector<int>ans;
        int a = -1, b = -1;
        int n = grid.size();
        unordered_map<int, int>mpp;
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[i].size();j++){
                mpp[grid[i][j]]++;
            }
        }
        // for(auto i : mpp){
        //     cout<<i.first<<" "<<i.second<<endl;
        // }
        
        for(int i = 0; i<=n*n;i++){
            if(mpp[i] == 2) a = i;
            else if(mpp[i] == 0) b = i;
        }
        return {a, b};

    }
};