class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        
        priority_queue<pair<char, int>>maxHeap;
        map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }
        for (auto [c, count] : freq) {
            maxHeap.push({c, count});
        }  
        string result = "";
        while(!maxHeap.empty()){
           auto[currchar, countchar] = maxHeap.top();
           maxHeap.pop();

           int use = min(countchar,repeatLimit);

           result.append(use, currchar);
           countchar -= use;

           if(countchar > 0){
             
             if(maxHeap.empty()){
                break;
            }

            auto [nextChar, nextCount] = maxHeap.top();
            maxHeap.pop();

            result += nextChar;
            nextCount--;

            maxHeap.push({currchar, countchar});

            if (nextCount > 0) {
                    maxHeap.push({nextChar, nextCount});
            }

            }
        }
        return result;
    }
};