class Solution {
public:
    string reorganizeString(string s) {
        int freq[26] = {0};
        priority_queue<pair<int, char>>pq;
        for(auto i : s){
            freq[i - 'a']++;
        }
        for(int i = 0;i<26;i++){
            if(freq[i] > 0){
                pq.push({freq[i], char(i + 'a')});
            }
        }
        string res = "";
        while(pq.size()>1){
            auto it = pq.top(); pq.pop();
            auto it1 = pq.top(); pq.pop();

            res += it.second;
            res += it1.second;

            if(--it.first > 0){
                pq.push(it);
            }
            if(--it1.first > 0) {
                pq.push(it1);
            }
        }
        if(!pq.empty()){
            if(pq.top().first > 1)
                return "";
            res += pq.top().second;
        }

        return res;
    }
};