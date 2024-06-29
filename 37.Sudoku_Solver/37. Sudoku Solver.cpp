#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool cellLegitCheck(vector<vector<char>>& board) {
    unordered_set<char> charSet;
    for (int cell = 0; cell < 9; cell++)
    {
        for (int i = 0; i < board.size(); i += 3)
        {
            for (int j = 0; j < board.size(); j += 3)
            {
                int border1 = i + 3;
                int border2 = j + 3;
                for (int x = i; x < border1; x++)
                {
                    for (int y = j; y < border2; y++)
                    {
                        if (charSet.find(board[x][y]) != charSet.end()) {
                            return false;
                        }
                        else
                        {
                            if (!((board[x][y]) == '.'))
                            {
                                charSet.insert((board[x][y]));
                            }
                        }
                    }
                }
                charSet.clear();
            }
        }
    }
    return true;
}

bool legitCheck(vector<vector<char>>& board, int row, int col) {
    unordered_set<char> charSet;
    for (int j = 0; j < board.size(); j++) {
        if (charSet.find(board[row][j]) != charSet.end()) {
            return false;
        }
        else
        {
            if (!((board[row][j]) == '.'))
            {
                charSet.insert((board[row][j]));
            }
        }
    }
    charSet.clear();
    for (int i = 0; i < board.size(); i++) {
        if (charSet.find(board[i][col]) != charSet.end()) {
            return false;
        }
        else
        {
            if (!((board[i][col]) == '.'))
            {
                charSet.insert((board[i][col]));
            }
        }
    }
    return true;
}

bool isValidSudoku(vector<vector<char>>& board) {
    if (!cellLegitCheck(board))
    {
        return false;
    }
    for (int i = 0; i < board.size(); i++) {
        int innerLength = board[i].size();
        for (int j = 0; j < innerLength; j++) {
            if (board[i][j] != '.')
            {
                if (!legitCheck(board, i, j))
                {
                    return false;
                }
            }
        }
    }
    return true;
}
//сам решить не смог, решение спизжено, но хотя бы понял че такое бэктрэкинг

class Solution {
public:
    bool row[9][10], col[9][10], square[9][10];

    bool dfs(int cell, vector<vector<char>>& board)
    {
        if (cell == 81) return true;

        int i = cell / 9, j = cell % 9;

        // This cell was written
        if (board[i][j] != '.') {
            return (dfs(cell + 1, board));
        }

        // was not writen
        for (int k = 1; k <= 9; k++)
        {
            if (!row[i][k] && !col[j][k] && !square[(i / 3) * 3 + j / 3][k])
            {
                board[i][j] = '0' + k;
                row[i][k] = col[j][k] = square[(i / 3) * 3 + j / 3][k] = true;
                if (dfs(cell + 1, board)) return true;
                board[i][j] = '.';
                row[i][k] = col[j][k] = square[(i / 3) * 3 + j / 3][k] = false;
            }
        }

        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    int k = board[i][j] - '0';
                    row[i][k] = col[j][k] = square[(i / 3) * 3 + j / 3][k] = true;

                }
            }
        }

        // Вывод состояния массивов после инициализации
        cout << "row array:" << endl;
        for (int i = 0; i < 9; ++i) {
            for (int k = 1; k <= 9; ++k) {
                cout << row[i][k] << " ";
            }
            cout << endl;
        }

        cout << "col array:" << endl;
        for (int j = 0; j < 9; ++j) {
            for (int k = 1; k <= 9; ++k) {
                cout << col[j][k] << " ";
            }
            cout << endl;
        }

        cout << "square array:" << endl;
        for (int k = 1; k <= 9; ++k) {
            for (int m = 0; m < 9; ++m) {
                cout << square[m][k] << " ";
                if ((m + 1) % 3 == 0) {
                    cout << "| ";
                }
            }
            cout << endl;
        }
        cout << endl;
        dfs(0, board);
    }
};

int main()
{
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    vector<vector<char>> board1 = {
        {'.','.','.','.','5','.','.','1','.'},
        {'.','4','.','3','.','.','.','.','.'},
        {'.','.','.','.','.','3','.','.','1'},
        {'8','.','.','.','.','.','.','2','.'},
        {'.','.','2','.','7','.','.','.','.'},
        {'.','1','5','.','.','.','.','.','.'},
        {'.','.','.','.','.','2','.','.','.'},
        {'.','2','.','9','.','.','.','.','.'},
        {'.','.','4','.','.','.','.','.','.'}
    };
    Solution s;
    s.solveSudoku(board);

    for (auto row : board) {
        for (auto it : row) {
            cout << it << " ";
        }
        cout << endl;
    }
}
/*
1 . 6
5 0 .
. . 7

02
01
00

02
12
22


00 03 06

30 33 36

60 63 66

*/