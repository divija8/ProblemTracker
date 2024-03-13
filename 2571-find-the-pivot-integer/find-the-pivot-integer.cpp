class Solution {
public:
    int pivotInteger(int n) {
        for(int i = 1; i <= n; i++){
            int leftSum = 0, rightSum = 0;
            for(int j = 1; j <= i; j++) leftSum += j;
            for(int k = n; k >= i; k--) rightSum += k;
            if(leftSum == rightSum){
                return i;
            }
        }
        return -1;
    }
};