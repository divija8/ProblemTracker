class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans = 0;
        int len = pref.size();
        for(int i = 0;i<words.size();i++){
            if(words[i].length() < len){
                continue;
            } else {
                string val = words[i].substr(0, len);
                if(val == pref){
                    ans++;
                }
            }
        }
        return ans;
    }
};