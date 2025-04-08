class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ct=0;
        unordered_map<int,int> mp;
        for(int i = nums.size()-1;i >= 0; i--){
            ct++;
            mp[nums[i]]++;
            if(mp.size()!=ct) break;
        }
        int ans = (nums.size()-mp.size()+2)/3;
        return ans;
    }
};