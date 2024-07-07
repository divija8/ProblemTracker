class Solution {
public:
    bool ok(vector<vector<char>>& board, int i, int j, char chk){
        for(int k=0; k<9; k++){
            if(k!=j && board[i][k]==chk){
                return false;
            }
            if(k!=i && board[k][j]==chk){
                return false;
            }
            int r=(3*(i/3)) + (k/3);
            int c=(3*(j/3)) + (k%3);
            if(r!=i && c!=j && board[r][c]==chk){
                return false;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j]!='.'){
                    if(!ok(board,i,j,board[i][j])){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};