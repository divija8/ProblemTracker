class Solution {
public:
    int findMin(vector<int>& arr) {
        int ans = INT_MAX;
        int low = 0, high = arr.size()-1;
        while(low <= high){
            int mid = (low + high)/2;
            if(arr[low] <= arr[mid]){
                ans = min(ans, arr[low]);
                low = mid+1;
            }else {
                high = mid-1;
                ans = min(ans, arr[mid]);
            }
        }
        return ans;
    }
};