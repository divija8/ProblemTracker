class Solution {
public:
    string compressedString(string word) {
        int count = 1, n = word.length();
        string ans = "";
        for (int i = 1; i < n; i++) {
            if (count == 9 || word[i] != word[i - 1]) {
                ans += to_string(count);
                ans += word[i - 1];
                count = 1;
            } else
                count++;
        }
        ans += to_string(count);
        ans += word[n - 1];
        return ans;
    }
};