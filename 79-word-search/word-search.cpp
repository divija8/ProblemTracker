// class Solution {
// public:
//  int ROWS, COLS;
// bool dfs(int i, int j, vector<vector<char>>&board, string word, int k){
//     // cout<<"("<<i<<", "<<j<<", "<<word[k]<<", "<<board[i][j]<<"); ";
    
//     if(k == word.size()) return true;
//     // cout<<"step1 : "<<ROWS<<" "<<COLS<<" - ";
//     // cout<<(  i >= ROWS || j >= COLS || board[i][j] != word[k] || board[i][j] == '_');
//     if(i < 0 || j < 0 || i >= ROWS || j >= COLS || board[i][j] != word[k] || board[i][j] == '_'){
//         return false;
//     }
//     cout<<"step2";
//     char c = board[i][j];
//     board[i][j] = '_';
//     cout<<"entered";
//     bool res = dfs(i, j+1, board, word, k+1)||
//                 dfs(i, j-1, board, word, k +1)||
//                 dfs(i-1, j, board, word, k + 1)||
//                 dfs(i+1, j, board, word, k +1);
//     board[i][j] = c;
//     return res;
// }
//     bool exist(vector<vector<char>>& board, string word) {
//         ROWS = board.size();
//         COLS = board[0].size();
//         for(int i = 0;i<ROWS;i++){
//             for(int j = 0;j<COLS;j++){
//                 cout<<board[i][j]<< " - ";
//                 if(dfs(i, j, board, word, 0)) {
//                     return true;
//                 }
//                 cout<<endl;
//             }
//         }
//         return false;
//     }
// };

class Solution {
public:
    int ROWS, COLS;

    bool exist(vector<vector<char>>& board, string word) {
        ROWS = board.size();
        COLS = board[0].size();

        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (dfs(board, word, r, c, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, string word, int r, int c, int i) {
        if (i == word.size()) {
            return true;
        }
        if (r < 0 || c < 0 || r >= ROWS || c >= COLS || 
            board[r][c] != word[i] || board[r][c] == '#') {
            return false;
        }

        board[r][c] = '#';
        bool res = dfs(board, word, r + 1, c, i + 1) ||
                   dfs(board, word, r - 1, c, i + 1) ||
                   dfs(board, word, r, c + 1, i + 1) ||
                   dfs(board, word, r, c - 1, i + 1);
        board[r][c] = word[i];
        return res;
    }
};