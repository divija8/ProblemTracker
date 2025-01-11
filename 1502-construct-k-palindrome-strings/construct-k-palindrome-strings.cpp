class Solution {
public:
    bool canConstruct(string s, int k) {
       if(s.size() < k) return false;
       vector<char>freq(26, 0);
       for(auto ch : s) {
            freq[ch-'a']++;
       }
       int even = 0, odd = 0;
       for(auto num : freq){
         if(num%2==0){
            even++;
         }else {
            odd++;
         }
       }
       if(odd > k) return false;
       return true;
    }
};