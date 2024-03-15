class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        unordered_map<string,bool> mp;
        int ans=0;
        for(auto ele:words){
            string st=ele;
            reverse(st.begin(),st.end());
            if(mp.find(st) != mp.end()){
                ans++;
            }
            mp[ele]=1;
        }
        return ans;
    }
};