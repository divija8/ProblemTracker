class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int l = 0, r = 0;
        int window = 0, max_window = 0;
        int max_score = 0;
        for(int r = 0;r<customers.size();r++){
            if(grumpy[r]){
                window += customers[r];
            }else {
                max_score+=customers[r];
            }
            if(r-l+1>minutes){
                if(grumpy[l]){
                    window-=customers[l];
                }
                l++;
            }
            max_window = max(window, max_window);
        }
        return max_window + max_score;
    }
};