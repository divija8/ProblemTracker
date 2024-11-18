class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans(n, 0);
        if(k>0) {
            int i=0, j=1, sum = 0, idx;
            while(j-i<=k) {
                    idx = j%n;
                    sum += code[idx];
                    j++;
            }
            ans[i] = sum;
            i++;
            while(i<n) {
                sum -= code[i];
                idx = j%n;
                sum += code[idx];
                ans[i] = sum;
                i++;
                j++;
            }
        } else if (k<0) {
            int i=0, j=-1, sum = 0, idx;
            while(i-j<=abs(k)) {
                    idx = (j + n)%n;
                    sum += code[idx];
                    j--;
            }
            j++;

            while(i<n) {
                ans[i] = sum;
                idx = (j + n)%n;
                sum -= code[idx];
                sum += code[i];

                i++;
                j++;
            }
        }
        
        return ans;
    }
};