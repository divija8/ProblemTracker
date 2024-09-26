class MyCalendar {
private :
    vector<pair<int, int>>bookings;
public:
    MyCalendar() {
        
    }
    bool book(int start, int end) {
        for(auto &val : bookings){
            int val1 = val.first;
            int val2 = val.second;
            if(start < val2 && end > val1){
                return false;
            }
        }
        bookings.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */