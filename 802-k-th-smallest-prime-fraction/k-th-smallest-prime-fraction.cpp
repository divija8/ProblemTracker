class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<int>ans;
        priority_queue<pair<double, pair<int,int>>>pq;
        for(int i=0;i<arr.size();i++){
            for(int j = i+1;j<arr.size();j++){
                double x = arr[i]/(arr[j] * 1.0);
                if(pq.size()==k){
                    if(x < pq.top().first) {
                        pq.pop();
                        pq.push({x,{arr[i],arr[j]}});

                    } 
                }  
                else
                {
                    pq.push({x,{arr[i],arr[j]}});
                }
            }
        }
        return {pq.top().second.first,pq.top().second.second};


    }
};