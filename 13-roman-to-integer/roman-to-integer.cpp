class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int>cmap;
        int ans = 0;
        cmap['I'] = 1, cmap['V'] = 5, cmap['X'] = 10, cmap['L'] = 50, cmap['C'] = 100,
        cmap['M'] = 1000, cmap['D'] = 500;
        for(int i = 0;i<s.size();i++){
            if(cmap[s[i]] < cmap[s[i + 1]]) ans -= cmap[s[i]];
            else {
                ans += cmap[s[i]];
            }
        }
        return ans;
    }
};