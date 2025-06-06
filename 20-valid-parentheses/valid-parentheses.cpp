class Solution {
public:
    bool isValid(string s) {
        stack<char>s1;
        for(int i = 0;i<s.size();i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                s1.push(s[i]);
            } else {
                if((!s1.empty()) && ((s1.top() == '(' && s[i] == ')') ||
                (s1.top() == '{' && s[i] == '}') ||  
                (s1.top() == '[' && s[i] == ']'))){
                    s1.pop();
                } else {
                    return false;
                }
            }
        } 
        return s1.size()!= 0 ? false : true;
    }
};