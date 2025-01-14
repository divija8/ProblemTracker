class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(), nums.end());
        for(int i = 0;i<nums.size();i++){
            if(i == 0 || (i>0 && nums[i] != nums[i-1])){
                int low = i+1, high = nums.size()-1, a = 0-nums[i];
                while(low<high){
                    if(nums[low] + nums[high] == a){
                        ans.push_back({nums[i], nums[low], nums[high]});
            
                        while(low < high && nums[low] == nums[low+1])low++;
                        while(low<high && nums[high]== nums[high-1])high--;
                        low++, high--;
                    }

                else if(nums[low] + nums[high] < a) low++;
                else high--;
            }
        }
    }
    return ans;
    }
};