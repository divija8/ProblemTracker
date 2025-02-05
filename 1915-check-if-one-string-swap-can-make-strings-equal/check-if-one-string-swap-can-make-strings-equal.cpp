class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int count = 0;
        vector<int>freq(26);
        if(s1.size() != s2.size()) return false;
        for(int i = 0;i<s1.size();i++){
            freq[s1[i]-'a']++;
            freq[s2[i]-'a']--;
            if(s1[i] != s2[i]) count++;
            if(count > 2) return false;
        }
        for(int i = 0;i<26;i++){
            if(freq[i] != 0) return false;
        }
    return true;
    }
};