class Solution {
public:
    int counsetbits(int n){
        int count = 0;
        while(n){
           count += (n & 1);
            n = n>>1;
        }
        return count;
    }
    vector<int> sortByBits(vector<int>& arr) {
      int n = arr.size();
      priority_queue<pair<int, int>>pq;
      for(auto i  : arr ){
         int val = counsetbits(i);
         pq.push({val, i});
      }
      int idx = n-1;
        while(!pq.empty()){
           arr[idx] = pq.top().second;
           pq.pop();
           idx--;
        }
        return arr;
    }
};