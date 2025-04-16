class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int>mpp;
        for(auto i : nums){
            mpp[i]++;
        }
        // for(auto i : mpp){
        //     cout << i.first << " "<< i.second<<endl;
        // }
        int c = 0;
        for(auto i : mpp){
            if(i.second >= 2){
                c += (i.second * (i.second -1))/2;
            }
        }
        return c;
    }
};