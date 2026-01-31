class Solution {
public:
    bool isValid(int i, int j, vector<string>& ans) {
        int n = ans.size();
        for (int k = 0; k < ans.size(); k++) {
            if (ans[i][k] == 'Q') {
                return false;
            }
        }

        for (int k = 0; k < ans.size(); k++) {
            if (ans[k][j] == 'Q') {
                return false;
            }
        }

        // upper-left
        for (int x = i, y = j; x >= 0 && y >= 0; x--, y--) {
            if (ans[x][y] == 'Q')
                return false;
        }

        // lower-left
        for (int x = i, y = j; x < n && y >= 0; x++, y--) {
            if (ans[x][y] == 'Q')
                return false;
        }

        // upper-right
        for (int x = i, y = j; x >= 0 && y < n; x--, y++) {
            if (ans[x][y] == 'Q')
                return false;
        }

        // lower-right
        for (int x = i, y = j; x < n && y < n; x++, y++) {
            if (ans[x][y] == 'Q')
                return false;
        }

        return true;
    }
    void nQueenSolver(int i, vector<string>& board, int n,
                      vector<vector<string>>& res) {
        if (i == n) {
            res.push_back(board);
            return;
        }

        for (int j = 0; j < n; j++) {
            if (isValid(i, j, board)) {
                board[i][j] = 'Q';
                nQueenSolver(i + 1, board, n, res);
                board[i][j] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> res;
        nQueenSolver(0, board, n, res);
        return res;
    }
};
