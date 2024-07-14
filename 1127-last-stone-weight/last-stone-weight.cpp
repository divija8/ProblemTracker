class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>max_heap;
        for(auto i : stones){                       
            max_heap.push(i);
        }
        while(max_heap.size()>1){
            int a = max_heap.top();
            max_heap.pop();
            int b = max_heap.top();
            max_heap.pop();
            if(a!=b){
                max_heap.push(a-b);
            }
        }
        if(max_heap.size() == 0) return 0;
        return max_heap.top();
        
    }
};