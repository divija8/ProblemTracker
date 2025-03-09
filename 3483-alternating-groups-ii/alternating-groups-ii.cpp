class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& nums, int k) {
        int i = 0, j = 1, n = nums.size(), count = 0;
        while(i < n){
            if(j - i + 1 < k){
                if(nums[j%n] == nums[(j-1)%n]){
                    i = j;
                }
            }else {
                if(nums[j % n] != nums[(j-1)%n]) count++, i++;
                else i = j;
            }
            j++;
        }
        return count;
    
    }
};
