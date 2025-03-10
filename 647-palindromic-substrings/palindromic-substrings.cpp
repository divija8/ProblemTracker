// class Solution {
// public:
//     int countSubstrings(string s) {
//         int res = 0, j, k;
//         for(int i = 0;i<s.size();i++){
//             j = i - 1;
//             k = i + 1;
//             while(j >= 0 && k < s.size() && s[k] == s[j]){
//                 j--;
//                 k++;
//                 res++;
//             }
//             j = i, k = i + 1;
//             while(j >= 0 && k < s.size() && s[k] == s[j]){
//                 j--;
//                 k++;
//                 res++;
//             }
//         }
//         return res;
//     }
// };
class Solution {
public:
    int countSubstrings(string s) {
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            int j = i, k = i;
            while (j >= 0 && k < s.size() && s[j] == s[k]) {
                res++;
                j--;
                k++;
            }
            
            j = i, k = i + 1;
            while (j >= 0 && k < s.size() && s[j] == s[k]) {
                res++;
                j--;
                k++;
            }
        }
        return res;
    }
};