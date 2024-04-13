class Solution {
public:
	int f(int num){
		int sum=0;
		while(num){
			sum+=num%10;
			num/=10;
		}
		return sum;
	}


	int differenceOfSum(vector<int>& nums) {
		int n= nums.size();
		int dsum=0;
		int sum=0;
		for(int i=0;i<n;i++){
			sum+=nums[i];
			dsum+=f(nums[i]);
		}
		return abs(sum-dsum);
	}
};