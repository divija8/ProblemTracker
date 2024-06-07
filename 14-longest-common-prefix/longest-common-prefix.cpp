class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string pref = strs[0];
        int pref_len = pref.length();
        for(int i = 1 ;i<strs.size();i++) {
            string s = strs[i];
            while (pref_len > s.length() || pref != s.substr(0, pref_len)){
                pref_len--;
                if(pref_len==0){
                    return "";
                }
            pref = pref.substr(0, pref_len);
            }
        }
     return pref;
    }

};