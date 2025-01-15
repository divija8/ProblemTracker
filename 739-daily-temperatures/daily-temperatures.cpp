class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
      stack<pair<int, int>>st;
      vector<int>res(temp.size(), 0);
      for(int i = 0;i<temp.size();i++){
        int t = temp[i];
        while(!st.empty() && t > st.top().first){
            auto val = st.top();
            st.pop();
            res[val.second] = i - val.second;
        }
        st.push({t, i});
      }
      return res;
    }
};