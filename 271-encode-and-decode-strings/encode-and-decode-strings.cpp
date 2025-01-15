class Codec {
public:

    // Encodes a list of strings to a single string.
   string encode(vector<string>& strs) {
        string res;
        for (auto s : strs) {
            res += to_string(s.size()) + "#" + s;
        }
        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string>ans;
        int i = 0;
        while(i<s.size()){
            int j = i;
            while(s[j] != '#'){
                j++;
            }
            int length = stoi(s.substr(i, j-i));
            i = j + 1;
            j = i + length;
            ans.push_back(s.substr(i, length));
            i = j;
        }
        return ans;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));