class Solution {
public:
    string frequencySort(string s) {
        string ans="";
        unordered_map<char,int>cmap;
        for(auto i : s){
            cmap[i]++;
        }
      priority_queue<pair<int,char>>pq;
      for(auto i : cmap) {
          pq.push({i.second,i.first});
      }
      string str;
        while (!pq.empty()) {
            while (cmap[pq.top().second]-- > 0) {
                str += pq.top().second;
            }
            pq.pop();
        }
        
        return str;
    }
};