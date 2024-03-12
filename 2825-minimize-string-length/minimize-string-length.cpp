class Solution {
public:
    int minimizedStringLength(string s) {
        set<char>s1;
        for(auto i : s){
            s1.insert(i);
        }
    return s1.size();
    }

};