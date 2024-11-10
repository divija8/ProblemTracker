class Solution {
public:
    int thirdMax(vector<int>& nums) {
         unordered_set<int> distincts;
        for (int i : nums) {
            distincts.insert(i);
        }
         vector<int> arr(distincts.begin(), distincts.end());
        sort(arr.begin(), arr.end(), greater<int>());

        if (arr.size() < 3) {
            return arr[0];
        }
        return arr[2];
    }
};