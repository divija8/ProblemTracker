class Solution {
public:
    vector<int> findClosestElements(vector<int>& nums, int k, int x) {
        priority_queue<pair<int,int>>pq;
        for(int i=0; i<nums.size(); i++)
        {
            pq.push({abs(x-nums[i]),nums[i]});
            if(pq.size()>k)
                pq.pop();
        }
        vector<int>ans;
        while(pq.size()!=NULL)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};


