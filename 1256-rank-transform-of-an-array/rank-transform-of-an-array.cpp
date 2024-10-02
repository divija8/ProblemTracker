class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>dup = arr;
        int rank = 1;
        sort(dup.begin(), dup.end());
        unordered_map<int, int>cmap;
        for(int i =0; i<dup.size();i++){
            if(cmap.find(dup[i]) == cmap.end()){
                cmap[dup[i]] = rank;
                rank++;
            }
        }
       for(int i = 0;i<arr.size();i++){
            arr[i] = cmap[arr[i]];
       }
        return arr;
    }
};