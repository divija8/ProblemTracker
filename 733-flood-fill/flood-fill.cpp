// class Solution {
// public:
//     vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
//         vector<int>dr = {-1, 1, 0, 0};
//         vector<int>dc = {0, 0, -1, 1};
//         int m = image.size();
//         int n = image[0].size();
//         int spoint = image[sr][sc];
//         if(color == spoint) return image;
//         queue<pair<int, int>>q;
//         q.push({sr, sc});
//         while(!q.empty()){
//             int r = q.front().first;
//             int c = q.front().second;
//             q.pop();
//             for(int i = 0; i<4;i++){
//                 int rn = r + dr[i];
//                 int cn = c + dc[i];
//                  if (rn >= 0 && rn < m && cn >= 0 && cn < n && image[rn][cn] == spoint) {
//                     image[rn][cn] = color; 
//                     q.push({rn, cn});
//                 }
//             }
//         }
//         return image;

//     }
// };

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        if(image[sr][sc]==color) return image;
        int startColor = image[sr][sc];
        image[sr][sc] = color;

        int rows = image.size();
        int cols = image[0].size();

        queue<pair<int, int>> q;
        q.push({sr, sc});
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};
        while(!q.empty())
        {
            int cx = q.front().first, cy = q.front().second;
            q.pop();
            
            for(int i = 0; i < 4; i++)
            {
                int x = cx + dx[i], y = cy + dy[i];
                if(x < 0 || 
                x >= rows || y < 0 || y >= cols
                 || image[x][y] == color)                                                   
                 continue;
                if(image[x][y] == startColor)
                {
                    image[x][y] = color;
                    q.push({x, y});
                }
            }
        }

        return image;
    }
};