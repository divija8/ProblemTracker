class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        constexpr int INF = INT_MAX;
        int rows = rooms.size();
        if (rows == 0) return;
        int cols = rooms[0].size();
        
        queue<pair<int, int>> q;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (rooms[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        const vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (auto [dx, dy] : directions) {
                int newX = x + dx;
                int newY = y + dy;

                if (newX >= 0 && newX < rows && newY >= 0 && newY < cols && rooms[newX][newY] == INF) {
                    rooms[newX][newY] = rooms[x][y] + 1;
                    q.push({newX, newY});
                }
            }
        }
    }
};