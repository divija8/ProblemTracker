class Solution {
public:
    long long minimumSteps(string s) {
        long long swaps = 0;
        int left = 0, right = s.size()-1;
        while(left < right){
            if(s[left] == '1') {
                if(s[right] == '0') {
                    swaps+= right - left;
                    left++;
                }
                right --;
        }else {
            if(s[right] == '1') right--;
            left++;
        }
        }
        return swaps;
    }
};