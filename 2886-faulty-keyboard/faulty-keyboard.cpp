class Solution {
public:
    string finalString(string s) {
        string ans="";
        for(auto k : s){
            if(k != 'i'){
                ans+=k;
            }
            else{
                reverse(ans.begin(),ans.end());
            }
        }
        return ans;
    }
};