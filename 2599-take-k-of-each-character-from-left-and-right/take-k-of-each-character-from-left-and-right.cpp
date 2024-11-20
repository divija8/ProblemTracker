class Solution {
public:
    bool c(vector<int>& temp,int k){
        for(auto it:temp){
            if(it<k) return false;
        }
        return true;
    }
    void mz(vector<int>& temp){
        temp[0] = 0;
        temp[1] = 0;
        temp[2] = 0;
    }
    int takeCharacters(string s, int k) {
        if(k==0) return 0;
        int m = s.length();
        int ans = 1e9;
        vector<int> temp(3,0);
        for(int i=0;i<m;i++){
          temp[s[i]-'a']++;
          if(c(temp,k)){
            ans = min(ans,i+1);
            break;
          }
        }
        mz(temp);
        for(int i=m-1;i>=0;i--){
            temp[s[i]-'a']++;
            if(c(temp,k)){
                ans=min(ans,m-i);
                break;
            }
        }
        mz(temp);
        s=s+s;
        int n = s.length();
        int i=0;
        int j=0;
        while(j<n){
            temp[s[j]-'a']++;
            while(i<m && j>=m && c(temp,k)){
                ans = min(ans,j-i+1);
                temp[s[i]-'a']--;
                i++;
            }
            j++;
        }
        if(ans>m) return -1;
        return ans;
    }
};