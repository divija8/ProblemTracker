class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int, int>>q;
        vector<pair<int, int>> v = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        int ans = 0;
        for(int i = 0; i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j] == '1'){
                    ans++;
                    q.push({i, j});
                    grid[i][j] = '-';
                    while(!q.empty()){
                        auto it = q.front();
                        q.pop();
                        for(int k = 0;k<4;k++){
                            int nr = it.first + v[k].first;
                            int nc = it.second + v[k].second;
                            if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]=='1'){
                                q.push({nr, nc});
                                grid[nr][nc]= '-';
                            }
                        }

                    }
                }
            }
        }
        return ans;
    }
};