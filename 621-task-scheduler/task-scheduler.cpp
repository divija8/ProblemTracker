class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
//         if (n == 0) return tasks.size();

//         unordered_map<char, int> freqMap;
//         int maxFreq = 0;
//         int maxFreqCount = 0;

//         for (char task : tasks) {
            
//             if (freqMap.find(task) != freqMap.end()) {
//                 freqMap[task]++;
//             } else {
//                 freqMap[task] = 1; 
//             }

//             if (freqMap[task] > maxFreq) {
//                 maxFreq = freqMap[task];
//                 maxFreqCount = 1;
//             } else if (freqMap[task] == maxFreq) {
//                 maxFreqCount++;
//             }
//         }

//         int totalIntervals = (maxFreq - 1) * (n + 1) + maxFreqCount;
//         return max(totalIntervals, (int)tasks.size());
        
        
        unordered_map<char, int>cmap;
        priority_queue<int>pq;
        queue<vector<int>>q;
        for(auto i : tasks){
            cmap[i]++;
        }
        for(auto i : cmap){
            pq.push(i.second);
        }
        int time = 0;
        while(!q.empty() || !pq.empty()){
            ++time;
            if(!pq.empty()){
                if(pq.top()-1){
                    q.push({pq.top()-1, time+n});
                }
                pq.pop();
            }
            if (!q.empty() && q.front()[1] == time){
                pq.push(q.front()[0]);
                q.pop();
            }
        }
        return time;
    }
};