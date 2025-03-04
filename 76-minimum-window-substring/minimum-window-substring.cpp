// class Solution {
// public:
//     string minWindow(string s, string t) {
//         unordered_map<char, int>mp1, mp2;
//         if(t.size() == 0) return "";
//         for(auto i : t) {
//             mp1[i]++;
//         }
//         int val1 = mp1.size();
//         int val2 = 0, res = INT_MAX;
//         pair<int, int> resp = {-1, -1};
//         int l = 0, r = 0;
//         for(r = 0;r<s.size();r++){
//             mp2[s[r]]++;
//             if(mp1.count(s[r]) && mp1[s[r]] == mp2[s[r]]){
//                 val2 ++;
//             }
//             while(val1 == val2){
//                 if((r-l+1) < res){
//                     res = r-l+1;
//                     resp = {l, r};
//                 }
//                 mp2[s[l]]--;
//                 if(mp1.count(s[l]) && mp2[s[l]] < mp1[s[l]]){
//                     val1--;
//                 }
//                 l++;
//             }
//         }
//         return res == INT_MAX ? "" : s.substr(resp.first, res);
//     }
// };

class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty()) return "";

        unordered_map<char, int> countT, window;
        for (char c : t) {
            countT[c]++;
        }

        int have = 0, need = countT.size();
        pair<int, int> res = {-1, -1};
        int resLen = INT_MAX;
        int l = 0;

        for (int r = 0; r < s.length(); r++) {
            char c = s[r];
            window[c]++;

            if (countT.count(c) && window[c] == countT[c]) {
                have++;
            }

            while (have == need) {
                if ((r - l + 1) < resLen) {
                    resLen = r - l + 1;
                    res = {l, r};
                }

                window[s[l]]--;
                if (countT.count(s[l]) && window[s[l]] < countT[s[l]]) {
                    have--;
                }
                l++;
            }
        }

        return resLen == INT_MAX ? "" : s.substr(res.first, resLen);
    }
};