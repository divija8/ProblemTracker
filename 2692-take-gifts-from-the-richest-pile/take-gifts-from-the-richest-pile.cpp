class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long ans = 0;
        priority_queue<long long>pq;
        for(auto i : gifts){
            pq.push(i);
        }
        for(int i = 0;i<k;i++){
            int ele = pq.top();
            pq.pop();
            pq.push(floor(sqrt(ele)));
        }
        while(!pq.empty()){
            ans+=pq.top();
            pq.pop();
        }
        return ans;
    }
};