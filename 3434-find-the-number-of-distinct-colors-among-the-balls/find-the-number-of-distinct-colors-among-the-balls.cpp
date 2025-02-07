class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        vector<int>result(queries.size());
        unordered_map<int, int>bmap;
        unordered_map<int, int>cmap;
        for(int i = 0;i<queries.size();i++){
            int x = queries[i][0];
            int y = queries[i][1];
            if(bmap.find(x)!= bmap.end()){
                
                cmap[bmap[x]]--;
                if(cmap[bmap[x]]==0) cmap.erase(bmap[x]);
            }
            bmap[x] = y;
            cmap[y]++;
            result[i] = (cmap.size());
        }
        return result;
    }
};