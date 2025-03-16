class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int>cmap;
        for(auto i : s){
            cmap[i]++;
        }
        priority_queue<pair<int, char>>pq;
        for(auto i : cmap){
            pq.push({i.second, i.first});
        }
        string res = "";
        while(!pq.empty()){
            int x = pq.top().first;
            char ch = pq.top().second;
            pq.pop();

            res.append(x, ch);
        }
        return res;
    }
};