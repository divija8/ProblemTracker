class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
         vector<int>indegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        for(auto it : prerequisites){
            int u = it[1];
            int v = it[0];
            adj[u].push_back(v);
        }
        for(int i = 0;i<numCourses;i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }
        queue<int>q;
        for(int i = 0;i<numCourses;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        vector<int>topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto i : adj[node]){
                indegree[i]--;
                if(indegree[i] == 0){
                    q.push(i);
                }
            }
        }
        if(topo.size() == numCourses){
            return topo;
        }
        return {};
    }
};