class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int sum = 0;
        for(int i = 0;i<nums.size();i++) {
            set<int>s1;
            for(int j=i;j<nums.size();j++) {
                s1.insert(nums[j]);
                sum+=s1.size()*s1.size();
            }
        }
        return sum;
    }
};