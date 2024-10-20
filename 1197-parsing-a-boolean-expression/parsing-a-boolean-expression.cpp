#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
    private:
    char evaluate(char op, string rem) {
        if (op == '&') {
            for (char c : rem) {
                if (c == 'f') return 'f';
            }
            return 't';
        } 
        else if (op == '|') {
            for (char c : rem) {
                if (c == 't') return 't';
            }
            return 'f';
        } 
        else if (op == '!') {
            return rem[0] == 't' ? 'f' : 't';
        }
        return 'f'; 
    }
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;  

        for (int i = 0; i < expression.size(); i++) {
            char c = expression[i];
            
            if (c == ',' || c == ' ') {
                continue; 
            }

            if (c == 't' || c == 'f' || c == '|' || c == '&' || c == '!') {
                st.push(c); 
            } 
            else if (c == ')') {
                string rem = "";
                while (st.top() != '(') {  
                    rem += st.top();
                    st.pop();
                }
                st.pop();  

                char op = st.top();  
                st.pop();

                char result = evaluate(op, rem);
                st.push(result); 
            } 
            else {
                st.push(c); 
            }
        }

        return st.top() == 't';  
    }
};