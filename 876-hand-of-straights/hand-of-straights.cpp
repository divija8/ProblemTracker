class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0) return false;
        sort(hand.begin(), hand.end());
        unordered_map<int, int>cmap;
        for(auto num : hand) {
            cmap[num]++;
        }
        for(auto i : hand){
            if(cmap[i] > 0) {
                for(int j = i ; j < i + groupSize; j++){
                    if(cmap[j] == 0) return false;
                    cmap[j]--;
                }
            }
        }
        return true;
    }
};