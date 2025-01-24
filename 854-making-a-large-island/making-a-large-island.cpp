class Solution {
public:
    int r, c;
    unordered_map<int, int> u;
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, -1, 0, 1};

    void dfs(int i, int j, vector<vector<int>>& grid, int num) {
        if(i<0 || j<0 || i>=r || j>=c || grid[i][j]<1) return;
        if(grid[i][j]==1) {
            grid[i][j] = num;
            u[num]++;
            dfs(i+1, j, grid, num);
            dfs(i, j+1, grid, num);
            dfs(i-1, j, grid, num);
            dfs(i, j-1, grid, num);
        }
        return;
    }

    bool isValid(int i, int j, vector<vector<int>>& grid) {
        if(i<0 || j<0 || i>=r || j>=c) return false;
        return true;
    }

    int largestIsland(vector<vector<int>>& grid) {
        r = grid.size();
        c = grid[0].size();
        int num = 2;
        int ans = 0;

        for(int i=0;i<r;i++) {
            for(int j=0;j<c;j++) {
                if(grid[i][j]==1) {
                    dfs(i, j, grid, num);
                    ans = max(ans, u[num]);
                    num++;
                }
            }
        }
        for(int i=0;i<r;i++) {
            for(int j=0;j<c;j++) {
                    // cout<<i<< " "<<j<<" - "<<grid[i][j]<<"\n";
                // cout<<
                if(grid[i][j]==0) {
                    // cout<<i<< " "<<j<<"\n";
                    unordered_set<int>us;
                    for(int k=0;k<4;k++) {
                        int ni = dx[k] + i;
                        int nj = dy[k] + j;
                        if(isValid(ni, nj, grid) && grid[ni][nj]!=0)
                            us.insert(grid[ni][nj]);
                    }
                    int ts = 0;
                    for(int it: us) {
                        ts += u[it];
                    }
                    ans = max(ans, 1+ts);
                    // cout<<"\n===\n";
                }
            }
        }
        return ans;

    }
};