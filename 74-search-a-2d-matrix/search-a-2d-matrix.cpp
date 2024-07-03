class Solution {
public:
    bool searchMatrix(vector<vector<int>>& m, int t) {
       int r=m.size(),c=m[0].size(),l=0,h=(r*c)-1;
       while(l<=h){
           int mid=l+(h-l)/2;
           if(m[mid/c][mid%c]==t) return true;
           if(m[mid/c][mid%c]<t){
               l=mid+1;
           }
           else {
               h=mid-1;
           }
       }
        return false;
        
            
    }
};