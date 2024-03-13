class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int ans = 0;
        vector<char>freq(26,0);
        for(int i=0;i<allowed.size();i++){
            freq[allowed[i]-'a']++;
        }
        for(int i=0;i< words.size();i++){
             bool flag = true;
            for(int j=0;j<words[i].size();j++){
                if(freq[words[i][j]-'a']==0){
                    flag = false;
                    break;
                }
            }
            if(flag){
                ans++;
            }
            }
        return ans;
        }
};