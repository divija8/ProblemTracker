class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int maxarea = 0;
        vector<pair<int, int>> v = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j]==1){
                    int currarea = 0;
                    queue<pair<int,int>> q;
                    grid[i][j] = '-';
                    q.push({i,j});
					
                    while(!q.empty()){
                        int x = q.front().first;
                        int y = q.front().second;
                        currarea++;
                        q.pop();
                        for(int k = 0;k<4;k++){
                            int newx = x + v[k].first;
                            int newy = y + v[k].second;
                            if(newx>=0 && newx<m && newy>=0 && newy<n && grid[newx][newy]==1){
                                q.push({newx,newy});
                                grid[newx][newy] = '-';
                            }
                        }
                    }
					
                    maxarea = max(maxarea,currarea); 
                }
            }
        }
        return maxarea;
    }
};