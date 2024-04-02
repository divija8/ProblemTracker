class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> indexS(200, 0); 
        vector<int> indexT(200, 0); 
        
        int len = s.length(); 
        
        if(len != t.length()) { 
            return false;
        }
        
        for(int i = 0; i < len; i++) { // Iterate through each character of the strings
            if(indexS[s[i]] != indexT[t[i]]) { // Check if the index of the current character in string s is different from the index of the corresponding character in string t
                return false; 
            }
            
            indexS[s[i]] = i + 1; 
            indexT[t[i]] = i + 1;
        }
        
        return true; // If the loop completes without returning false, strings are isomorphic
    }
};