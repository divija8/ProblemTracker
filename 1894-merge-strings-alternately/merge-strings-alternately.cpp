class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i = 0, j = 0, m = word1.size(), n = word2.size();
        string result = "";
        while(i< m || j < n){
            if(i< m){
                result += word1[i];
                i++;
            }
            if(j< n){
                result += word2[j];
                j++;
            }
        }
        return result;
    }
};