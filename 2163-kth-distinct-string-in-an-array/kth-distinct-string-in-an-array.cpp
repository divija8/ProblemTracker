class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        string s;
        unordered_map<string,int>cm;
        for(int i=0;i<arr.size();i++) {
            cm[arr[i]]++;
        }
       for(int i=0;i<arr.size();i++) {
           if(cm[arr[i]]==1) {
               k--;
               if(k==0) return arr[i];
           }
       }
        return "";
    }
};