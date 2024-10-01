class Solution {
public:
    int findGCD(vector<int>& nums) {
      int max = *max_element(nums.begin(), nums.end());
      int min = *min_element(nums.begin(), nums.end());
        int ans =1;
        for(int i =2;i<=min;i++){
            if(max %i ==0 && min % i ==0){
                ans = i;
            }
        } 
        return ans; 
    }
};