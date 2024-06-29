class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int>cmap;
        for(auto i : s1){
            cmap[i]++;
        }
        int i = 0, j = 0;
        int k = s1.size();
        int m = s2.size();
        int count = cmap.size();
        while(j<m){
            if(cmap.find(s2[j])!= cmap.end()){
                cmap[s2[j]]--;
                if(cmap[s2[j]]==0){
                    count--;
                } 
            }
                if(j-i+1<k){
                    j++;
                }
                else if(j-i+1 == k){
                    if(count == 0) {
                      return true;
                    }
                    if(cmap.find(s2[i])!=cmap.end()){
                         cmap[s2[i]]++;
                    if(cmap[s2[i]] == 1){
                        count++;
                    }
                }
                i++;
                j++;
            
            }
        }
        return false;
    }
};