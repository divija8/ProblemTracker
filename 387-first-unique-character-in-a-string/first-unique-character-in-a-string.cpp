class Solution {
public:
    int firstUniqChar(string s) {

        unordered_map<char, int>cmap;
        for(auto i : s){
            cmap[i]++;
        }
        for(int i = 0;i<s.size();i++){
            if(cmap[s[i]] == 1){
                return i;
            }
        }
        return -1;
    }
};