class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>s1;
        for(int i = 0;i<tokens.size();i++){
            if(tokens[i] == "+" || tokens[i] == "-" || 
            tokens[i] == "*" || tokens[i] == "/") {
                int b = s1.top();
                s1.pop();
                int a = s1.top();
                s1.pop();
                if(tokens[i] == "+"){
                    s1.push(a+b);
                }
                else if(tokens[i] == "-"){
                    s1.push(a-b);
                }
                else if(tokens[i] == "*"){
                    s1.push(a*b);
                }
                else if (tokens[i] == "/"){
                    s1.push(a/b);
                }

            } else {
                s1.push(stoi(tokens[i]));
            }
        }
        return s1.top();
    }
};

