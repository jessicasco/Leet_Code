public class Solution {
    public boolean solveSudoku(char[][] board) {
        for (int i=0; i < 9; ++i) {
            for (int j=0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    for (int k=1; k <= 9; ++k) {
                        board[i][j] = (char)((int)'0' + k);
                        if (isValid(board, i, j) && solveSudoku(board))
                            return true;
                    }
                    board[i][j] = '.';
                    return false;
                }
            }
        }
        return true;
    }
    boolean isValid(char[][] board, int x, int y) {
        for (int i=0; i < 9; i++)
            if (i != x && board[i][y] == board[x][y])
                return false;
        for (int i=0; i < 9; i++)
            if (i != y && board[x][i] == board[x][y])
                return false;
        for (int i=(x/3)*3; i < ((x/3)+1)*3; i++)
            for (int j=(y/3)*3; j < ((y/3)+1)*3; j++)
                if (i != x && j != y && board[i][j] == board[x][y])
                    return false;
        return true;
    }
}
