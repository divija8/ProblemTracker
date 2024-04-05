class Solution {
public:
    string makeGood(string s) {
        if(s.empty()) return "";

        string result = "";
        for(int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if(!result.empty() && abs(c - result.back()) == 32) {
                result.pop_back(); 
            } else {
                result.push_back(c); 
            }
        }
        return result;
    }
};
