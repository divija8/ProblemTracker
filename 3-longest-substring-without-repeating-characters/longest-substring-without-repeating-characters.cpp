class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0, max_length = 0;
        unordered_set<int>cset;
        while(j<s.size()){
            if(cset.find(s[j]) == cset.end()){
                cset.insert(s[j]);
                max_length = max(max_length, j-i+1);
                j++;
            } else {
                cset.erase(s[i]);
                i++;
            }
        }
        return max_length;
    }
};