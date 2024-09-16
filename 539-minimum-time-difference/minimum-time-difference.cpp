class Solution {
public:
    int findMinDifference(vector<string>& tp) {
        vector<int>minutes;
        for(int i = 0; i<tp.size();i++){
            string temp = tp[i];
            int hr = stoi(temp.substr(0,2));
            int minu = stoi(temp.substr(3,2));
            int total = hr * 60 + minu;
            minutes.push_back(total);
        }
        sort(minutes.begin(), minutes.end());
        int mini=INT_MAX;
        for(int i=0;i<minutes.size()-1;i++){
            int diff=minutes[i+1]-minutes[i];
            mini=min(diff,mini);
        }
        int lastDiff = (1440 + minutes[0]) - minutes[minutes.size() - 1];
        mini = min(mini, lastDiff);
        
        return mini;

    }
};