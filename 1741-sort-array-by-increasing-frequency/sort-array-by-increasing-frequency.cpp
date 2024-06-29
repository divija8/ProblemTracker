#define ppi pair<int,int>

class Solution {
public:
    class Compare{
        public:
        bool operator()(ppi below, ppi above){
            if(below.first == above.first){ 
                return below.second < above.second; 
            }
            return below.first > above.first;
        }
    };
    vector<int> frequencySort(vector<int>& nums) {
        vector<int>ans;
        unordered_map<int,int>cmap;
        for(auto i : nums){
            cmap[i]++;
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, Compare>pq;
        for(auto i : cmap){
            pq.push({i.second, i.first});
        }
        while(pq.size() > 0){
            int freq = pq.top().first;
            int val = pq.top().second;
            
            for(int i=0; i<freq; i++){
                ans.push_back(val);
            }
            
            pq.pop();
        }
        
        return ans;
    }
};