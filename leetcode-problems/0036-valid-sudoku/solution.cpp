class Solution {
public:
    bool sudokuValidator(vector<vector<char>>& board, int row, int col) {
        // row check;
        unordered_set<char> temp;
        for (int j = 0; j < 9; j++) {
            if (board[row][j] != '.') {
                if (temp.count(board[row][j])) {
                    return false;
                } else {
                    temp.insert(board[row][j]);
                }
            }
        }

        temp.clear();
        for (int i = 0; i < 9; i++) {
            if (board[i][col] != '.') {
                if (temp.count(board[i][col])) {
                    return false;
                } else {
                    temp.insert(board[i][col]);
                }
            }
        }

        temp.clear();

        int boxRowStart = (row) / 3 * 3;
        int boxColunStart = (col) / 3 * 3;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i + boxRowStart][j + boxColunStart] != '.') {
                    if (temp.count(board[i + boxRowStart][j + boxColunStart])) {
                        return false;
                    } else {
                        temp.insert(board[i + boxRowStart][j + boxColunStart]);
                    }
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    if (!sudokuValidator(board, i, j)) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
