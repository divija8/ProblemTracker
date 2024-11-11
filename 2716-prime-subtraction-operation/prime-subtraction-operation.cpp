class Solution {
    vector<int> isPrime;

    void sieveAlgo() {
        for(int i = 2; i*i < 1000; ++i) {
            if(isPrime[i]) {
                for(int j = i*i; j < 1000; j += i) {
                    isPrime[j] = false;
                }
            }
        }
    }

public:
    bool primeSubOperation(vector<int>& nums) {
        isPrime.resize(1000, true);
        isPrime[0] = false; 
        isPrime[1] = false; 

        sieveAlgo();

        for(int i = nums.size()-2; i >= 0; --i) {
            if(nums[i] < nums[i + 1])
                continue;

            for(int val = 2; val < nums[i]; ++val) {
                if(isPrime[val] && nums[i] - val < nums[i + 1]) {
                    nums[i] -= val;
                    break;
                }
            }

            
            if(nums[i] >= nums[i + 1])
                return false;
        }

        return true;
    }
};