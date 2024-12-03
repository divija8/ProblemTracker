class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string spaced = "";
        int i = 0, j = 0, n = s.size(), m = spaces.size();
        while(i<n){
            if((j<m) && (spaces[j] == i)){
                spaced += " ";
                j++;
            }
            spaced.push_back(s[i++]);
        }
        return spaced;
    }
};