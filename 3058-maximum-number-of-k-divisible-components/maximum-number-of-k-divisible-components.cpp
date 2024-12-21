class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        
        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int ans = 1;
        vector<bool> visited(n, false);

        function<int(int)> DFS = [&](int idx) {
            visited[idx] = true;
            int treeSum = values[idx];

            for (int childIdx : adj[idx]) {
                if (visited[childIdx]) continue;

                int childTreeSum = DFS(childIdx);
                if (childTreeSum % k == 0) {        
                    ans++;
                } else {
                    treeSum += (childTreeSum % k);
                }
            }
            return treeSum;
        };
        int treeSum = DFS(0);
        return ans;
    }
};