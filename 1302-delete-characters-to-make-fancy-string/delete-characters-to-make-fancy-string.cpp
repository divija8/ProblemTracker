class Solution {
public:
    string makeFancyString(string s) {
        string ans;
        int count = 1;
        ans.push_back(s[0]);
        for(int i = 1;i<s.size();i++){
            if(s[i] == s[i-1]){
                count++;
                if(count > 2) {
                    continue;
                }
                ans.push_back(s[i]);
            } else {
                count = 1;
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};