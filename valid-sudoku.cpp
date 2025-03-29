class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Use sets to check rows, columns, and sub-grids
        for (int i = 0; i < 9; ++i) {
            unordered_set<char> rowSet;
            unordered_set<char> colSet;
            unordered_set<char> boxSet;
            
            for (int j = 0; j < 9; ++j) {
                // Check row
                if (board[i][j] != '.' && rowSet.find(board[i][j]) != rowSet.end()) {
                    return false;
                }
                if (board[i][j] != '.') {
                    rowSet.insert(board[i][j]);
                }
                
                // Check column
                if (board[j][i] != '.' && colSet.find(board[j][i]) != colSet.end()) {
                    return false;
                }
                if (board[j][i] != '.') {
                    colSet.insert(board[j][i]);
                }
                
                // Check sub-grid
                int rowStart = 3 * (i / 3);
                int colStart = 3 * (i % 3);
                if (board[rowStart + j / 3][colStart + j % 3] != '.' &&
                    boxSet.find(board[rowStart + j / 3][colStart + j % 3]) != boxSet.end()) {
                    return false;
                }
                if (board[rowStart + j / 3][colStart + j % 3] != '.') {
                    boxSet.insert(board[rowStart + j / 3][colStart + j % 3]);
                }
            }
        }
        return true;
    }
};
