class Solution {
public:
    vector<vector<string>> result;
    unordered_set<int> cols, diag, antiDiag;

    void backtrack(int row, int n, vector<string>& board) {
        if(row == n) {
            result.push_back(board);
            return;
        }

        for(int col=0; col<n; col++) {
            if(cols.count(col) || diag.count(row-col) || antiDiag.count(row+col))
                continue;                          // unsafe, skip

            // place queen
            board[row][col] = 'Q';
            cols.insert(col);
            diag.insert(row-col);
            antiDiag.insert(row+col);

            backtrack(row+1, n, board);            // next row

            // remove queen (backtrack)
            board[row][col] = '.';
            cols.erase(col);
            diag.erase(row-col);
            antiDiag.erase(row+col);
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        backtrack(0, n, board);
        return result;
    }
};