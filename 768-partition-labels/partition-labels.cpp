class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int>cmap;
        for(int i = 0 ; i<s.size();i++){
            cmap[s[i]] = i;
        }
        vector<int>res;
        int size = 0, end = 0;
        for(int j = 0 ; j<s.size();j++){
            size += 1;
            end = max(cmap[s[j]], end);
            if(j == end){
                res.push_back(size);
                size = 0;
            }
        }
        return res;
    }
};