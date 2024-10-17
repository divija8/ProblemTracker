class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int i = 0 , j = 0 , n = nums.size();
        long long ans = 0 , sum = 0;
        unordered_map<int,int> m;

        while(j < n){
            m[nums[j]]++;
            sum+=nums[j];

            if((j-i+1) < k){
                j++;
            }
            else{
                if(m.size() == k){
                    ans = max(ans,sum);
                }

                sum-=nums[i];
                m[nums[i]]--;
                
                if(m[nums[i]] == 0){
                    m.erase(nums[i]);
                }
                i++;
                j++;
            }
        }
        return ans;
    }
};