class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>>pairing;
        for(int i = 0;i<position.size();i++){
            pairing.push_back({position[i], speed[i]});
        }
        sort(pairing.rbegin(), pairing.rend());
        stack<double> fleetStack;
        for(auto p : pairing){
            double time = (double)(target - p.first) / p.second;
            if (fleetStack.empty() || time > fleetStack.top()) {
                fleetStack.push(time);
            }
        }
        return fleetStack.size();
    }
};