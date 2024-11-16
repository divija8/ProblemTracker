class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int i = 0, j = 1;
        int n = nums.size();
        vector<int> result(n-k+1, -1);
        int count = 0;
        if(k == 1) {
            return nums;
        }
        count+= 1;
        while(j< nums.size()) {
           
           if(nums[j]-1 == nums[j-1]){
                count+=1;
                if(count == k) {
                    result[i] = nums[j];
                    count--;
                    i++;
                }
           }
           else {
                while(i != j){
                    count--;
                    i++;
                }
                count+=1;
           }
           j++;
        }
        return result;
    }
};