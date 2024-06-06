class Solution {
public:
    int maxDepth(string s) {
        int res = 0, cur = 0;
        for(auto i : s){
            if(i == '(') cur++;
            else if (i == ')') cur--;
            res = max(res, cur);
        }
        return res;
    }
};