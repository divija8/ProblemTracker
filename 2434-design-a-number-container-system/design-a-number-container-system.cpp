class NumberContainers {
public:
    unordered_map<int, int>um;
    unordered_map<int, set<int>>sm;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(um.find(index)!=um.end()) {
            sm[um[index]].erase(index);
            if(sm[um[index]].size() == 0) sm.erase(um[index]);

        }
        um[index] = number;
        sm[number].insert(index);
    }
    
    int find(int number) {
        if(sm.find(number) == sm.end()) return -1;
        return *sm[number].begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */