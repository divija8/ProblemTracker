class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // unordered_set<char>cset;
        // int maxi = INT_MIN;
        // int j = 0, i = 0;
        // while(i < s.size()){
        //     if(cset.find(s[i]) != cset.end()){
        //         cset.insert(s[i]);
        //         maxi = max(maxi, i - j + 1);
        //         i++;

        //     }else {
        //         cset.erase(s[j]);
        //         j++;
        //     }
        // }
        // return maxi;
        unordered_map<char, int>cmap;
        int j = 0;
        int maxi = 0;
        for(int i = 0; i<s.size();i++){
            if(cmap.find(s[i]) != cmap.end()) {
                j = max(j, cmap[s[i]] + 1); 
            }
            cmap[s[i]] = i;
            maxi = max(maxi, i - j + 1);
        }
        return maxi;
    }
};