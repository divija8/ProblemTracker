class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int N = nums.size();  
        vector<int> nge(N, -1);  
        stack<int> ans;

        for(int i = 2 * N - 1; i >= 0; i--) {  
            while (!ans.empty() && ans.top() <= nums[i % N]) {  
                ans.pop();  
            }  
            if (i < N) {  
                nge[i] = ans.empty() ? -1 : ans.top();  
            }  
            ans.push(nums[i % N]);  
        }  

        return nge;  
    }
};
