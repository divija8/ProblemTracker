class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        stack<int>st;
        for(int i = arr.size()-1; i >= 0;i--){
            int c_val = arr[i];
            if(st.empty()){
                arr[i] = -1;
            }
            else {
                arr[i] = st.top();
            }
            if(st.empty() || st.top() <= c_val){
                st.push(c_val);
            }
        }
       return arr; 

    }
};