class Solution {
public:
    vector<int> productExceptSelf(vector<int>& arr) {
    int n =arr.size();
     vector<int>prefix(n);
     vector<int>product(n);
      prefix[0]=1; 
      for(int i=1;i<n;i++)
     {
        prefix[i]=prefix[i-1]*arr[i-1];
     }
    int suffixproduct=1;
    for(int i=n-1;i>=0;i--)
    {
        product[i]=suffixproduct*prefix[i];
        suffixproduct*=arr[i];
    }
    return product;
    }
};