class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int>res(prices);
        stack<int>s;
        int n = prices.size();
        for(int i = 0;i<n;i++){
            while(s.empty() == false && prices[i] <= prices[s.top()]){
                res[s.top()] = prices[s.top()] - prices[i];
                s.pop();
            }
            s.push(i);
        }
    return res;

    }
};