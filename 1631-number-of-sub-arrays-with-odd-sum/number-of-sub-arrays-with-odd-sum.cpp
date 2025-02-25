class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int ecount1 = 0 , ocount1 = 0, ans = 0;
        int ecount2 = 0 , ocount2 = 0;
        int mod = 1e9 + 7;
        for(int i = 0;i < arr.size();i++){
            if(arr[i] % 2 == 0){
                ecount2 = 1 + ecount1;
            } else {
                ecount2 = ocount1;
                ocount2 = 1 + ecount1;
            }
            ans += ocount2 % mod;
            ans = ans % mod;
            ecount1 = ecount2;
            ocount1 = ocount2;
        }
        return ans;
    }
};