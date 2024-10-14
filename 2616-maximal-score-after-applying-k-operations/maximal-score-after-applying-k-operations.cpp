class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int>ans;
        for(auto i : nums){
            ans.push(i);
        }
        long long score = 0;
        while(k--){
            int num = ans.top();
            ans.pop();
            score += num;
            if(num % 3 == 0) ans.push(num/3);
            else ans.push((num/3)+1);
        }
        return score;

    }
};