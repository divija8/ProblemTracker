class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>>adj(n + 1);
        for(auto i :  times){
            adj[i[0]].push_back({i[1], i[2]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        vector<int>dist(n+1, 1e9);
        dist[k] = 0;
        pq.push({0, k});
        while(!pq.empty()){
            auto [dis, node] = pq.top();
            pq.pop();
            if(dis > dist[node]) continue;
            for(auto &nei : adj[node]){
                int newNode = nei.first;
                int edgeWei = nei.second;
                int newTime = dis + edgeWei;

                if(newTime < dist[newNode]){
                    dist[newNode] = newTime;
                    pq.push({newTime, newNode});
                }

            }
        }
        int maxTime = *max_element(dist.begin() + 1, dist.end());
        return maxTime == 1e9 ? -1 : maxTime;
    }
};