class Solution {
public:
    void dfs(int node, vector<bool> &vis, vector<vector<int>>& v) {
        vis[node] = true;
        for(int nn: v[node]) {
            if(!vis[nn])
                dfs(nn, vis, v);
        }
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()!=n-1) return false;
        
        vector<bool> vis(n, false);
        vector<vector<int>> v(n);
        
        for(int i=0;i<edges.size();i++) {
            v[edges[i][0]].push_back(edges[i][1]);
            v[edges[i][1]].push_back(edges[i][0]);
        }

        dfs(0, vis, v);

        for(int i=0;i<n;i++) {
            if(!vis[i]) return false;
        }
        return true;
    }
};