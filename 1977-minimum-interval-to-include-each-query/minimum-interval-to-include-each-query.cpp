#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        // Step 1: Sort intervals by start time
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b) {
            return a[0] < b[0];
        });

        // Step 2: Sort the queries and keep original for final mapping
        vector<int> sortedQueries = queries;
        sort(sortedQueries.begin(), sortedQueries.end());

        // Step 3: Result map for each query
        map<int, int> res;

        // Step 4: Min-heap storing {interval_length, interval_end}
        auto cmp = [](const vector<int>& a, const vector<int>& b) {
            return a[0] > b[0] || (a[0] == b[0] && a[1] > b[1]);
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> minHeap(cmp);

        int i = 0; // index for intervals

        for (auto q : sortedQueries) {
            // Add all intervals whose start <= q
            while (i < intervals.size() && intervals[i][0] <= q) {
                int l = intervals[i][0];
                int r = intervals[i][1];
                minHeap.push({r - l + 1, r});
                i++;
            }

            // Remove intervals that end before q
            while (!minHeap.empty() && minHeap.top()[1] < q) {
                minHeap.pop();
            }

            // Record smallest valid interval length or -1
            res[q] = minHeap.empty() ? -1 : minHeap.top()[0];
        }

        // Step 5: Construct final result in original query order
        vector<int> result(queries.size());
        for (int j = 0; j < queries.size(); j++) {
            result[j] = res[queries[j]];
        }

        return result;
    }
};