class Solution {
    #define ll long long
    #define pii pair<int, int>

public:
    long long findScore(vector<int>& nums) {
        priority_queue<pii, vector<pii>, greater<pii>>pq;
        for(int i = 0;i<nums.size();i++) {
            pq.push(make_pair(nums[i], i));
        }
        unordered_set<int>cset;
        ll sum = 0;
        while(!pq.empty()) {
            pii cur = pq.top();
            pq.pop();

            int ele = cur.first;
            int index = cur.second;

            if(cset.count(index)) {
                continue;
            }
            sum += ele;
            cset.insert(index);
            cset.insert(index-1);
            cset.insert(index+1);
        }
        return sum;
    }
};