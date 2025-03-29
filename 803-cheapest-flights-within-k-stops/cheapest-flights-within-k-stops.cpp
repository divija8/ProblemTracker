class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>>adj(n);
        for(auto fval : flights){
            adj[fval[0]].push_back({fval[1], fval[2]});
        }
        queue<pair<int, pair<int, int>>>q;
        q.push({0, {src, 0}});
        vector<int>dist(n+1, 1e9);
        dist[src] = 0;
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;
            if(stops > k) continue;
            for(auto nei : adj[node]){
                int adjNode = nei.first;
                int edgW = nei.second;

                if(cost + edgW < dist[adjNode] && stops <= k){
                    dist[adjNode] = cost + edgW;
                    q.push({stops + 1, {adjNode, cost + edgW}});
                }
            }
        }
        if(dist[dst] == 1e9) return -1;
        return dist[dst];

    }
};