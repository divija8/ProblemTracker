class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<pair<int, int>>>adj(points.size());
        for(int i = 0 ;i < points.size();i++){
            int x1 = points[i][0], y1 = points[i][1];
            for(int j = i + 1; j< points.size();j++){
                int x2 = points[j][0], y2 = points[j][1];
                int dist = abs(x1- x2) + abs(y1 - y2);
                adj[i].push_back({dist, j});
                adj[j].push_back({dist, i});
            }
        }
        int res = 0;
        unordered_set<int>visited;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>>pq;
        pq.push({0, 0});
        while(!pq.empty()){
            auto [dist, node] = pq.top();
            pq.pop();
            if(visited.find(node) != visited.end()){
                continue;
            }
            res += dist;
            visited.insert(node);
            for(auto edg : adj[node]){
                if(visited.find(edg.second) == visited.end()){
                    pq.push({edg.first, edg.second});
                }
            }
        }
        return res;
        
    }
};