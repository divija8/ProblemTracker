#define pi pair<int,int> 
class Compare {
public:
    bool operator()(pi below, pi above)
    {
        if (below.first > above.first) {
            return true;
        }
        else if (below.first == above.first
                 && below.second < above.second) {
            return true;
        }
        return false;
    }
};


class Solution {
    public:
    vector<int>frequencySort(vector<int>&nums){
        unordered_map<int,int>cmap;
        for(auto i : nums){
            cmap[i]++;
        }
        priority_queue<pi,vector<pi>,Compare>pq;
        for(auto i : cmap){
            pq.push({i.second, i.first});
        }
        int i = 0;
        while(!pq.empty())
        {
            pi top = pq.top();
            pq.pop();
            while(top.first--)
                nums[i++] = top.second;
        }
        return nums;
    }
};