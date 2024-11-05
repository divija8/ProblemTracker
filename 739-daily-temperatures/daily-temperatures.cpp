class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> answer(n, 0);
        stack<int> monoStack;
        for (int currDay = 0; currDay < n; ++currDay) {
            while (!monoStack.empty() && temperatures[monoStack.top()] < temperatures[currDay]) {
                int prevDay = monoStack.top();
                monoStack.pop();
                answer[prevDay] = currDay - prevDay;
            }
            monoStack.push(currDay);
        }
        return answer;
    }
};