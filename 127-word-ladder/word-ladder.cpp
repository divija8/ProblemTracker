// class Solution {
// public:
//     int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
//         unordered_set<string>cset(wordList.begin(), wordList.end());
//         queue<pair<string, int>>que;
//         que.push({beginWord, 1});
//         cset.erase(beginWord);

//         while(!que.empty()){
//             string word = que.front().first;
//             int steps = que.front().second;
//             if(word == endWord) return steps;
//             for(int i = 0; i < word.size() ; i++){
//                 char org = word[i];
//                 for(char ch = 'a'; ch <= 'z'; ch++) {
//                     word[i] = ch;
//                     if(cset.find(word) != cset.end()) {
//                         cset.erase(word);
//                         que.push({word, steps + 1});
//                     }
//                 }
//                 word[i] = org;
//             }
//         }
//         return 0;
        
//     }
// };


class Solution {
public:
    int ladderLength(string start, string end, vector<string>& arr) {
        unordered_set<string>st(arr.begin(), arr.end());
        queue<pair<string, int>>q;
        q.push({start, 1});
        st.erase(start);
        while(!q.empty()){
            string str = q.front().first;
            int count = q.front().second;
            q.pop();
            if(str == end) return count;
            for(int i = 0;i < str.size();i++){
                char org = str[i];
                for(char c = 'a';c <= 'z';c++){
                    str[i] = c;
                    if(st.find(str) != st.end()){
                        st.erase(str);
                        q.push({str, (count+1)});
                    }
                }
                str[i] = org;
            }
        }
        return 0;
    }
};