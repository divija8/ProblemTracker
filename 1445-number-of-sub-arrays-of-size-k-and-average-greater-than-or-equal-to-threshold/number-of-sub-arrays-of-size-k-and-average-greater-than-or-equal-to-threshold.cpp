class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int i = 0, j = 0, n = arr.size(), ans = 0, sum = 0;
        while(j<n){
            sum+=arr[j];
            if((j-i+1) < k){
                j++;
            }
            else{
                double avg = (double)sum/k;
                if(avg >= threshold){
                    ans++;
                }
                j++;
                sum-=arr[i];
                i++;
            }
        }
        return ans;
    }
};